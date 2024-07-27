#include "FtdcTraderApiImpl.h"
#include <regex>

#define EXCHANGE_SH "SSE"
#define EXCHANGE_SZ "SZSE"
#define EXCHANGE_SHFE "SHFE"
#define EXCHANGE_CFFEX "CFFEX"
#define EXCHANGE_DCE "DCE"
#define EXCHANGE_CZCE "CZCE"
#define EXCHANGE_INE "INE"
#define EXCHANGE_HKEX "HKEX"
#define EXCHANGE_BSE "BSE"

// openctp's extend
#define OPENCTP_FTDC_PC_EQUITY 'E'
#define OPENCTP_FTDC_PC_BOND 'B'
#define OPENCTP_FTDC_PC_FUND 'D'

CThostFtdcTraderApi *CThostFtdcTraderApi::CreateFtdcTraderApi(const char *pszFlowPath)
{
	return new CFtdcTraderApiImpl(pszFlowPath);
}

const char *CThostFtdcTraderApi::GetApiVersion()
{
#ifdef V6_6_9
	return "V6_6_9";
#elif V6_6_7
	return "V6_6_7";
#elif V6_6_1_P1
	return "V6_6_1_P1";
#elif V6_5_1
	return "6.5.1";
#elif V6_3_19
	return "6.3.19_P1";
#else
	return "6.3.15";
#endif
}

CFtdcTraderApiImpl::CFtdcTraderApiImpl(const char *pszFlowPath)
{
	m_pUserApi = CUTApi::CreateTstpTraderApi(pszFlowPath);
	m_pUserApi->RegisterSpi(this);

	m_pSpi = NULL;
	memset(TradingDay, 0x00, sizeof(TradingDay));
	memset(m_BrokerID,0x00,sizeof(m_BrokerID));
	memset(m_UserID, 0x00, sizeof(m_UserID));
	memset(m_InvestorID, 0x00, sizeof(m_InvestorID));
	ThostRspInfoNotSupported.ErrorID = 99;
	strncpy(ThostRspInfoNotSupported.ErrorMsg, "Not supported",sizeof(ThostRspInfoNotSupported.ErrorMsg)-1);
}

void CFtdcTraderApiImpl::Init()
{
	m_pUserApi->Init();
}

int CFtdcTraderApiImpl::Join()
{
	m_pUserApi->Join();
	return 0;
}

void CFtdcTraderApiImpl::Release()
{
	m_pUserApi->Release();
	m_pUserApi = NULL;
	delete this;
}

const char *CFtdcTraderApiImpl::GetTradingDay()
{
	return TradingDay;
}

void CFtdcTraderApiImpl::RegisterFront(char *pszFrontAddress)
{
	m_pUserApi->RegisterFront(pszFrontAddress);
}

void CFtdcTraderApiImpl::RegisterFensUserInfo(CThostFtdcFensUserInfoField * pFensUserInfo)
{

}
void CFtdcTraderApiImpl::RegisterNameServer(char *pszNsAddress)
{
	// tcp://ip:port/EnvID/NodeID
	m_pUserApi->RegisterFront(pszFrontAddress);
}

void CFtdcTraderApiImpl::RegisterSpi(CThostFtdcTraderSpi *pSpi)
{
	m_pSpi = pSpi;
	if(!pSpi)
		m_pUserApi->RegisterSpi(NULL);
}
		
void CFtdcTraderApiImpl::SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	m_pUserApi->SubscribePrivateTopic((UT_TE_RESUME_TYPE)nResumeType);
}

void CFtdcTraderApiImpl::SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType)
{
	m_pUserApi->SubscribePublicTopic((UT_TE_RESUME_TYPE)nResumeType);
}

void CFtdcTraderApiImpl::OnTime(const boost::system::error_code& err)
{
	// This function will be called when timer is canceled or time changed.
	if (err) {
		if (err == boost::asio::error::operation_aborted) {
			return;
		}
	}

	m_pTimer->expires_from_now(boost::posix_time::seconds(1));
	m_pTimer->async_wait(boost::bind(&CFtdcTraderApiImpl::OnTime, this, boost::asio::placeholders::error));
}

///用户登录请求
int CFtdcTraderApiImpl::ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLogin, int nRequestID)
{
	strncpy(m_BrokerID, pReqUserLogin->BrokerID, sizeof(m_BrokerID) - 1);
	strncpy(m_UserID, pReqUserLogin->UserID, sizeof(m_UserID) - 1);
	strncpy(m_InvestorID, pReqUserLogin->UserID, sizeof(m_InvestorID) - 1);

	CTORATstpReqUserLoginField LoginReq;

	memset(&LoginReq,0x00,sizeof(LoginReq));
	LoginReq.LogInAccountType=TORA_TSTP_LACT_UserID;
	strncpy(LoginReq.DepartmentID, pReqUserLogin->BrokerID, sizeof(LoginReq.DepartmentID) - 1);
	strncpy(LoginReq.LogInAccount,pReqUserLogin->UserID,sizeof(LoginReq.LogInAccount)-1);
	strncpy(LoginReq.Password,pReqUserLogin->Password,sizeof(LoginReq.Password)-1);
	strncpy(LoginReq.UserProductInfo,pReqUserLogin->UserProductInfo,sizeof(LoginReq.UserProductInfo)-1);
	snprintf(LoginReq.TerminalInfo,sizeof(LoginReq.TerminalInfo),"PC;IIP=NA;IPORT=NA;LIP=%s;MAC=%s;HD=%s;@%s",
		pReqUserLogin->ClientIPAddress,pReqUserLogin->MacAddress,pReqUserLogin->LoginRemark,pReqUserLogin->UserProductInfo);
	return m_pUserApi->ReqUserLogin(&LoginReq, nRequestID);
}

///用户退出请求
int CFtdcTraderApiImpl::ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID)
{
	CTORATstpUserLogoutField LogoutReq;

	memset(&LogoutReq,0x00,sizeof(LogoutReq));
	strncpy(LogoutReq.UserID, pUserLogout->UserID,sizeof(LogoutReq.UserID)-1);
	return m_pUserApi->ReqUserLogout(&LogoutReq, nRequestID);
}

///用户密码修改请求
int CFtdcTraderApiImpl::ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID)
{
	CTORATstpUserPasswordUpdateField UserPasswordUpdate;

	memset(&UserPasswordUpdate,0,sizeof(UserPasswordUpdate));
	strncpy(UserPasswordUpdate.UserID,pUserPasswordUpdate->UserID,sizeof(UserPasswordUpdate.UserID)-1);
	strncpy(UserPasswordUpdate.OldPassword,pUserPasswordUpdate->OldPassword,sizeof(UserPasswordUpdate.OldPassword)-1);
	strncpy(UserPasswordUpdate.NewPassword,pUserPasswordUpdate->NewPassword,sizeof(UserPasswordUpdate.NewPassword)-1);

	return m_pUserApi->ReqUserPasswordUpdate(&UserPasswordUpdate, nRequestID);
}

///报单录入请求
int CFtdcTraderApiImpl::ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID)
{
	CTORATstpInputOrderField Req;
	memset(&Req, 0, sizeof(Req));
	strcpy(Req.InvestorID, pInputOrder->InvestorID);
	strcpy(Req.SecurityID, pInputOrder->InstrumentID);
	Req.OrderRef = atol(pInputOrder->OrderRef);

	if (strcmp(pInputOrder->ExchangeID, EXCHANGE_SH) == 0) {
		strcpy(Req.ShareholderID, m_ShareholderID_SSE);
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	}
	else if (strcmp(pInputOrder->ExchangeID, EXCHANGE_SZ) == 0) {
		strcpy(Req.ShareholderID, m_ShareholderID_SZSE);
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	}
	else if (strcmp(pInputOrder->ExchangeID, EXCHANGE_BSE) == 0) {
		strcpy(Req.ShareholderID, m_ShareholderID_BSE);
		Req.ExchangeID = TORA_TSTP_EXD_BSE;
	}
	else if (strlen(pInputOrder->ExchangeID) > 0) {
		strcpy(Req.ShareholderID, m_ShareholderID_HKEX);
		Req.ExchangeID = TORA_TSTP_EXD_HK;
	}

	Req.Direction = pInputOrder->Direction == THOST_FTDC_D_Buy ? TORA_TSTP_D_Buy : TORA_TSTP_D_Sell;

	switch (pInputOrder->OrderPriceType) {
	case THOST_FTDC_OPT_AnyPrice:
		Req.OrderPriceType = TORA_TSTP_OPT_AnyPrice;
		break;
	case THOST_FTDC_OPT_LimitPrice:
		Req.OrderPriceType = TORA_TSTP_OPT_LimitPrice;
		break;
	case THOST_FTDC_OPT_BestPrice:
		Req.OrderPriceType = TORA_TSTP_OPT_BestPrice;
		break;
	default:
		break;
	}

	Req.LimitPrice = pInputOrder->LimitPrice;
	Req.VolumeTotalOriginal = pInputOrder->VolumeTotalOriginal;

	switch (pInputOrder->TimeCondition) {
	case THOST_FTDC_TC_IOC:
		Req.TimeCondition = TORA_TSTP_TC_IOC;
		break;
	case THOST_FTDC_TC_GFS:
		Req.TimeCondition = TORA_TSTP_TC_GFS;
		break;
	case THOST_FTDC_TC_GFD:
		Req.TimeCondition = TORA_TSTP_TC_GFD;
		break;
	case THOST_FTDC_TC_GTD:
		Req.TimeCondition = TORA_TSTP_TC_GTD;
		break;
	case THOST_FTDC_TC_GTC:
		Req.TimeCondition = TORA_TSTP_TC_GTC;
		break;
	case THOST_FTDC_TC_GFA:
		Req.TimeCondition = TORA_TSTP_TC_GFA;
		break;
	default:
		break;
	}

	switch (pInputOrder->VolumeCondition) {
	case THOST_FTDC_VC_AV:
		Req.VolumeCondition = TORA_TSTP_VC_AV;
		break;
	case THOST_FTDC_VC_MV:
		Req.VolumeCondition = TORA_TSTP_VC_MV;
		break;
	case THOST_FTDC_VC_CV:
		Req.VolumeCondition = TORA_TSTP_VC_CV;
		break;
	default:
		break;
	}

	Req.ForceCloseReason = TORA_TSTP_FCC_NotForceClose;
	Req.Operway = TORA_TSTP_OPERW_PCClient;
	strncpy(Req.BusinessUnitID, pInputOrder->InvestUnitID, sizeof(Req.BusinessUnitID) - 1);

	return m_pUserApi->ReqOrderInsert(&Req, nRequestID);
}

//报单录入应答	
void CFtdcTraderApiImpl::OnRspOrderInsert(CTORATstpInputOrderField* pInputOrderField, CTORATstpRspInfoField* pRspInfo, int nRequestID)
{
	if (m_pSpi)
	{
		CThostFtdcRspInfoField* pThostRspInfo = NULL;

		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}

		CThostFtdcInputOrderField* pThostInputOrder = NULL;
		CThostFtdcInputOrderField ThostInputOrder;

		if (pInputOrderField)
		{
			memset(&ThostInputOrder, 0x00, sizeof(ThostInputOrder));
			strncpy(ThostInputOrder.BrokerID, m_BrokerID, sizeof(ThostInputOrder.BrokerID) - 1);
			strncpy(ThostInputOrder.UserID, m_UserID, sizeof(ThostInputOrder.UserID) - 1);
			strncpy(ThostInputOrder.InvestorID, pInputOrderField->InvestorID, sizeof(ThostInputOrder.InvestorID) - 1);
			if (pInputOrderField->ExchangeID == TORA_TSTP_EXD_SSE)
				strncpy(ThostInputOrder.ExchangeID, EXCHANGE_SH, sizeof(ThostInputOrder.ExchangeID) - 1);
			else if (pInputOrderField->ExchangeID == TORA_TSTP_EXD_SZSE)
				strncpy(ThostInputOrder.ExchangeID, EXCHANGE_SZ, sizeof(ThostInputOrder.ExchangeID) - 1);
			else if (pInputOrderField->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostInputOrder.ExchangeID, EXCHANGE_BSE, sizeof(ThostInputOrder.ExchangeID) - 1);
			else if (pInputOrderField->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostInputOrder.ExchangeID, EXCHANGE_HKEX, sizeof(ThostInputOrder.ExchangeID) - 1);
			strncpy(ThostInputOrder.InstrumentID, pInputOrderField->SecurityID, sizeof(ThostInputOrder.InstrumentID) - 1);
			snprintf(ThostInputOrder.OrderRef, sizeof(ThostInputOrder.OrderRef), "%d", pInputOrderField->OrderRef);
			if (pInputOrderField->OrderPriceType == TORA_TSTP_OPT_LimitPrice)
				ThostInputOrder.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
			else
				ThostInputOrder.OrderPriceType = THOST_FTDC_OPT_AnyPrice;
			ThostInputOrder.Direction = pInputOrderField->Direction == TORA_TSTP_D_Buy ? THOST_FTDC_D_Buy : THOST_FTDC_D_Sell;
			ThostInputOrder.CombOffsetFlag[0] = pInputOrderField->Direction == TORA_TSTP_D_Buy ? THOST_FTDC_OF_Open : THOST_FTDC_OF_Close;
			ThostInputOrder.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
			ThostInputOrder.LimitPrice = pInputOrderField->LimitPrice;
			ThostInputOrder.VolumeTotalOriginal = pInputOrderField->VolumeTotalOriginal;
			ThostInputOrder.MinVolume = 0;

			switch (pInputOrderField->TimeCondition) {
			case TORA_TSTP_TC_IOC:
				ThostInputOrder.TimeCondition = THOST_FTDC_TC_IOC;
				break;
			case TORA_TSTP_TC_GFS:
				ThostInputOrder.TimeCondition = THOST_FTDC_TC_GFS;
				break;
			case TORA_TSTP_TC_GFD:
				ThostInputOrder.TimeCondition = THOST_FTDC_TC_GFD;
				break;
			case TORA_TSTP_TC_GTD:
				ThostInputOrder.TimeCondition = THOST_FTDC_TC_GTD;
				break;
			case TORA_TSTP_TC_GTC:
				ThostInputOrder.TimeCondition = THOST_FTDC_TC_GTC;
				break;
			case TORA_TSTP_TC_GFA:
				ThostInputOrder.TimeCondition = THOST_FTDC_TC_GFA;
				break;
			default:
				break;
			}
			
			ThostInputOrder.VolumeCondition = THOST_FTDC_VC_AV;
			ThostInputOrder.ContingentCondition = THOST_FTDC_CC_Immediately;
			ThostInputOrder.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
			ThostInputOrder.IsAutoSuspend = 0;
			ThostInputOrder.UserForceClose = 0;
			strncpy(ThostInputOrder.GTDDate, pInputOrderField->GTDate, sizeof(ThostInputOrder.GTDDate) - 1);
			pThostInputOrder = &ThostInputOrder;
		}
		m_pSpi->OnRspOrderInsert(pThostInputOrder, pThostRspInfo, nRequestID, true);
	}
}


///报单操作请求
int CFtdcTraderApiImpl::ReqOrderAction(CThostFtdcInputOrderActionField *pOrderAction, int nRequestID)
{
	CTORATstpInputOrderActionField Req;
	memset(&Req, 0, sizeof(Req));
	Req.OrderRef = atol(pOrderAction->OrderRef);
	Req.OrderActionRef = pOrderAction->OrderActionRef;
	Req.FrontID = pOrderAction->FrontID;
	Req.SessionID = pOrderAction->SessionID;
	strncpy(Req.OrderSysID, pOrderAction->OrderSysID, sizeof(Req.OrderSysID) - 1);
	if (strcmp(pOrderAction->ExchangeID, EXCHANGE_SH) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	}
	else if (strcmp(pOrderAction->ExchangeID, EXCHANGE_SZ) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	}
	else if (strcmp(pOrderAction->ExchangeID, EXCHANGE_BSE) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_BSE;
	}
	else if (strlen(pOrderAction->ExchangeID) > 0) {
		Req.ExchangeID = TORA_TSTP_EXD_HK;
	}
	Req.ActionFlag = pOrderAction->ActionFlag == THOST_FTDC_AF_Delete ? TORA_TSTP_AF_Delete : TORA_TSTP_AF_Modify;
	Req.Operway = TORA_TSTP_OPERW_PCClient;

	return m_pUserApi->ReqOrderAction(&Req, nRequestID);
}

//撤单应答	
void CFtdcTraderApiImpl::OnRspOrderAction(CTORATstpInputOrderActionField* pInputOrderActionField, CTORATstpRspInfoField* pRspInfo, int nRequestID)
{
	if (m_pSpi)
	{

		CThostFtdcRspInfoField* pThostRspInfo = NULL;

		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}

		CThostFtdcInputOrderActionField* pThostOrderAction = NULL;
		CThostFtdcInputOrderActionField  ThostOrderAction;
		if (pInputOrderActionField)
		{
			memset(&ThostOrderAction, 0, sizeof(ThostOrderAction));
			if (pInputOrderActionField->ExchangeID == TORA_TSTP_EXD_SSE)
				strncpy(ThostOrderAction.ExchangeID, EXCHANGE_SH, sizeof(ThostOrderAction.ExchangeID) - 1);
			else if (pInputOrderActionField->ExchangeID == TORA_TSTP_EXD_SZSE)
				strncpy(ThostOrderAction.ExchangeID, EXCHANGE_SZ, sizeof(ThostOrderAction.ExchangeID) - 1);
			else if (pInputOrderActionField->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostOrderAction.ExchangeID, EXCHANGE_BSE, sizeof(ThostOrderAction.ExchangeID) - 1);
			else if (pInputOrderActionField->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostOrderAction.ExchangeID, EXCHANGE_HKEX, sizeof(ThostOrderAction.ExchangeID) - 1);
			strncpy(ThostOrderAction.OrderSysID, pInputOrderActionField->OrderSysID, sizeof(ThostOrderAction.OrderSysID) - 1);
			strncpy(ThostOrderAction.BrokerID, m_BrokerID, sizeof(ThostOrderAction.BrokerID) - 1);
			strncpy(ThostOrderAction.UserID, m_UserID, sizeof(ThostOrderAction.UserID) - 1);
			ThostOrderAction.SessionID = pInputOrderActionField->SessionID;
			ThostOrderAction.FrontID = pInputOrderActionField->FrontID;
			snprintf(ThostOrderAction.OrderRef, sizeof(ThostOrderAction.OrderRef),"%d",pInputOrderActionField->OrderRef);
			ThostOrderAction.OrderActionRef = pInputOrderActionField->OrderActionRef;
			ThostOrderAction.ActionFlag = pInputOrderActionField->ActionFlag == TORA_TSTP_AF_Modify ? THOST_FTDC_AF_Modify : THOST_FTDC_AF_Delete;
			pThostOrderAction = &ThostOrderAction;
		}

		m_pSpi->OnRspOrderAction(pThostOrderAction, pThostRspInfo, nRequestID, true);
	}
}


///报单查询请求
int CFtdcTraderApiImpl::ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID)
{
	CTORATstpQryOrderField Req;
	memset(&Req, 0, sizeof(Req));

	if (strcmp(pQryOrder->ExchangeID, EXCHANGE_SH) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	}
	else if (strcmp(pQryOrder->ExchangeID, EXCHANGE_SZ) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	}
	else if (strlen(pQryOrder->ExchangeID) > 0) {
		Req.ExchangeID = TORA_TSTP_EXD_HK;
	}
	strncpy(Req.SecurityID, pQryOrder->InstrumentID, sizeof(Req.SecurityID) - 1);

	return m_pUserApi->ReqQryOrder(&Req, nRequestID);
}

///成交单查询请求
int CFtdcTraderApiImpl::ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID)
{	
	CTORATstpQryTradeField Req;
	memset(&Req, 0, sizeof(Req));

	if (strcmp(pQryTrade->ExchangeID, EXCHANGE_SH) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	}
	else if (strcmp(pQryTrade->ExchangeID, EXCHANGE_SZ) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	}
	else if (strlen(pQryTrade->ExchangeID) > 0) {
		Req.ExchangeID = TORA_TSTP_EXD_HK;
	}
	strncpy(Req.SecurityID, pQryTrade->InstrumentID, sizeof(Req.SecurityID) - 1);

	return m_pUserApi->ReqQryTrade(&Req, nRequestID);
}

///可用投资者账户查询请求
int CFtdcTraderApiImpl::ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID)
{
	CTORATstpQryInvestorField Req;
	memset(&Req, 0, sizeof(Req));
	strncpy(Req.InvestorID, pQryInvestor->InvestorID, sizeof(Req.InvestorID) - 1);

	return m_pUserApi->ReqQryInvestor(&Req, nRequestID);
}

///投资者资金账户查询请求
int CFtdcTraderApiImpl::ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID)
{
	CTORATstpQryTradingAccountField Req;
	memset(&Req, 0, sizeof(Req));
	strncpy(Req.InvestorID, pQryTradingAccount->InvestorID, sizeof(Req.InvestorID) - 1);

	return m_pUserApi->ReqQryTradingAccount(&Req, nRequestID);
}

//资金账户查询
void CFtdcTraderApiImpl::OnRspQryTradingAccount(CTORATstpTradingAccountField* pTradingAccount, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (m_pSpi)
	{
		CThostFtdcTradingAccountField* pCTPTradingAccount = NULL;
		CThostFtdcTradingAccountField CTPTradingAccount;
		if (pTradingAccount)
		{
			memset(&CTPTradingAccount, 0, sizeof(CTPTradingAccount));
			strncpy(CTPTradingAccount.BrokerID, m_BrokerID, sizeof(CTPTradingAccount.BrokerID) - 1);
			strncpy(CTPTradingAccount.AccountID, pTradingAccount->AccountID, sizeof(CTPTradingAccount.AccountID) - 1);
			CTPTradingAccount.PreBalance = pTradingAccount->PreDeposit;
			CTPTradingAccount.Available = pTradingAccount->UsefulMoney;
			CTPTradingAccount.Withdraw = pTradingAccount->Withdraw;
			CTPTradingAccount.Deposit = pTradingAccount->Deposit;
			if(pTradingAccount->CurrencyID == TORA_TSTP_CID_CNY)
				strcpy(CTPTradingAccount.CurrencyID, "CNY");
			else if (pTradingAccount->CurrencyID == TORA_TSTP_CID_HKD)
				strcpy(CTPTradingAccount.CurrencyID, "HKD");
			else if (pTradingAccount->CurrencyID == TORA_TSTP_CID_USD)
				strcpy(CTPTradingAccount.CurrencyID, "USD");

			CTPTradingAccount.FrozenCash = pTradingAccount->FrozenCash;
			CTPTradingAccount.FrozenCommission = pTradingAccount->FrozenCommission;
			CTPTradingAccount.WithdrawQuota = pTradingAccount->FetchLimit;
			pCTPTradingAccount = &CTPTradingAccount;
		}
		CThostFtdcRspInfoField* pThostRspInfo = NULL;
		CThostFtdcRspInfoField  ThostRspInfo;
		if (NULL != pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}

		m_pSpi->OnRspQryTradingAccount(pCTPTradingAccount, pThostRspInfo, nRequestID, bIsLast);
	}
}

//查询股东账户
void CFtdcTraderApiImpl::OnRspQryShareholderAccount(CTORATstpShareholderAccountField* pShareholderAccount, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (pShareholderAccount && pShareholderAccount->ExchangeID == TORA_TSTP_EXD_SSE)
		strncpy(m_ShareholderID_SSE, pShareholderAccount->ShareholderID, sizeof(m_ShareholderID_SSE)-1);
	else if (pShareholderAccount && pShareholderAccount->ExchangeID == TORA_TSTP_EXD_SZSE)
		strncpy(m_ShareholderID_SZSE, pShareholderAccount->ShareholderID, sizeof(m_ShareholderID_SZSE) - 1);
	else if (pShareholderAccount && pShareholderAccount->ExchangeID == TORA_TSTP_EXD_BSE)
		strncpy(m_ShareholderID_BSE, pShareholderAccount->ShareholderID, sizeof(m_ShareholderID_BSE) - 1);
	else if (pShareholderAccount && pShareholderAccount->ExchangeID == TORA_TSTP_EXD_HK)
		strncpy(m_ShareholderID_HKEX, pShareholderAccount->ShareholderID, sizeof(m_ShareholderID_HKEX) - 1);
}


///合约查询请求
int CFtdcTraderApiImpl::ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID)
{
	CTORATstpQrySecurityField Req;
	memset(&Req,0,sizeof(Req));

	if (strcmp(pQryInstrument->ExchangeID, EXCHANGE_SH) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	}
	else if (strcmp(pQryInstrument->ExchangeID, EXCHANGE_SZ) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	}
	else if (strcmp(pQryInstrument->ExchangeID, EXCHANGE_BSE) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_BSE;
	}
	else if (strcmp(pQryInstrument->ExchangeID, EXCHANGE_HKEX) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_HK;
	}
	
	strncpy(Req.SecurityID, pQryInstrument->InstrumentID, sizeof(Req.SecurityID) - 1);
	Req.ProductID = pQryInstrument->ProductID[0];

	return m_pUserApi->ReqQrySecurity(&Req, nRequestID);
}

///交易所查询请求
int CFtdcTraderApiImpl::ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID)
{
	CTORATstpQryExchangeField Req;
	memset(&Req, 0, sizeof(Req));

	if (strcmp(pQryExchange->ExchangeID, EXCHANGE_SH) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	}
	else if (strcmp(pQryExchange->ExchangeID, EXCHANGE_SZ) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	}
	else if (strcmp(pQryExchange->ExchangeID, EXCHANGE_BSE) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_BSE;
	}
	else if (strcmp(pQryExchange->ExchangeID, EXCHANGE_HKEX) == 0) {
		Req.ExchangeID = TORA_TSTP_EXD_HK;
	}

	return m_pUserApi->ReqQryExchange(&Req, nRequestID);
}

//查询交易所
void CFtdcTraderApiImpl::OnRspQryExchange(CTORATstpExchangeField* pExchange, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (m_pSpi)
	{
		CThostFtdcRspInfoField* pThostRspInfo = NULL;

		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}

		CThostFtdcExchangeField* pThostExchange = NULL;
		CThostFtdcExchangeField  ThostExchange;

		if (pExchange)
		{
			memset(&ThostExchange, 0x00, sizeof(ThostExchange));
			if (pExchange->ExchangeID == TORA_TSTP_EXD_SSE)
				strncpy(ThostExchange.ExchangeID, EXCHANGE_SH, sizeof(ThostExchange.ExchangeID) - 1);
			else if (pExchange->ExchangeID == TORA_TSTP_EXD_SZSE)
				strncpy(ThostExchange.ExchangeID, EXCHANGE_SZ, sizeof(ThostExchange.ExchangeID) - 1);
			else if (pExchange->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostExchange.ExchangeID, EXCHANGE_HKEX, sizeof(ThostExchange.ExchangeID) - 1);
			else if (pExchange->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostExchange.ExchangeID, EXCHANGE_BSE, sizeof(ThostExchange.ExchangeID) - 1);
			pThostExchange = &ThostExchange; 
		}
		return m_pSpi->OnRspQryExchange(pThostExchange, pThostRspInfo, nRequestID, bIsLast);
	}
}

///投资者持仓查询请求
int CFtdcTraderApiImpl::ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID)
{
	CTORATstpQryPositionField Req;
	
	memset(&Req, 0, sizeof(Req));
	strncpy(Req.InvestorID, m_UserID, sizeof(Req.InvestorID) - 1);
	if (strcmp(pQryInvestorPosition->ExchangeID, EXCHANGE_SH) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	else if (strcmp(pQryInvestorPosition->ExchangeID, EXCHANGE_SZ) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	else if (strcmp(pQryInvestorPosition->ExchangeID, EXCHANGE_BSE) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_BSE;
	else if (strcmp(pQryInvestorPosition->ExchangeID, EXCHANGE_HKEX) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_HK;
	strncpy(Req.SecurityID, pQryInvestorPosition->InstrumentID, sizeof(Req.SecurityID) - 1);

	return m_pUserApi->ReqQryPosition(&Req, nRequestID);
}

///投资者手续费率查询请求
int CFtdcTraderApiImpl::ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID)
{
	CTORATstpQryInvestorTradingFeeField Req = {0};

	strncpy(Req.DepartmentID, m_BrokerID, sizeof(Req.DepartmentID) - 1);
	strncpy(Req.InvestorID, pQryInstrumentCommissionRate->InvestorID, sizeof(Req.InvestorID) - 1);
	if (strcmp(pQryInstrumentCommissionRate->ExchangeID, EXCHANGE_SH) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_SSE;
	else if (strcmp(pQryInstrumentCommissionRate->ExchangeID, EXCHANGE_SZ) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_SZSE;
	else if (strcmp(pQryInstrumentCommissionRate->ExchangeID, EXCHANGE_BSE) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_BSE;
	else if (strcmp(pQryInstrumentCommissionRate->ExchangeID, EXCHANGE_HKEX) == 0)
		Req.ExchangeID = TORA_TSTP_EXD_HK;

	return m_pUserApi->ReqQryInvestorTradingFee(&Req, nRequestID);
}

///投资者保证金率查询请求
int CFtdcTraderApiImpl::ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID)
{
	static CThostFtdcInstrumentMarginRateField ThostInvestorMargin;
	memset(&ThostInvestorMargin,0x00,sizeof(ThostInvestorMargin));
	strncpy(ThostInvestorMargin.BrokerID,m_BrokerID,sizeof(ThostInvestorMargin.BrokerID)-1);
	strncpy(ThostInvestorMargin.InvestorID,m_InvestorID,sizeof(ThostInvestorMargin.InvestorID)-1);
	strncpy(ThostInvestorMargin.InstrumentID,pQryInstrumentMarginRate->InstrumentID,sizeof(ThostInvestorMargin.InstrumentID)-1);
	ThostInvestorMargin.HedgeFlag = pQryInstrumentMarginRate->HedgeFlag;
	ThostInvestorMargin.LongMarginRatioByMoney=1.0;
	ThostInvestorMargin.ShortMarginRatioByMoney=1.0;
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryInstrumentMarginRate, m_pSpi, &ThostInvestorMargin, nullptr, nRequestID, true));
	return 0;
}

///投资者结算结果确认
int CFtdcTraderApiImpl::ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID)
{
	memcpy(&ThostSettlementInfoConfirmField,pSettlementInfoConfirm,sizeof(ThostSettlementInfoConfirmField));

	strncpy(ThostSettlementInfoConfirmField.BrokerID,m_BrokerID,sizeof(ThostSettlementInfoConfirmField.BrokerID)-1);
	strncpy(ThostSettlementInfoConfirmField.InvestorID,m_InvestorID,sizeof(ThostSettlementInfoConfirmField.InvestorID)-1);
	strncpy(ThostSettlementInfoConfirmField.AccountID,pSettlementInfoConfirm->AccountID,sizeof(ThostSettlementInfoConfirmField.AccountID)-1);
	struct tm *t;
	time_t tt;
	tt=time(NULL);
	t=localtime(&tt);
	snprintf(ThostSettlementInfoConfirmField.ConfirmDate,sizeof(ThostSettlementInfoConfirmField.ConfirmDate),"%04d%02d%02d",t->tm_year+1900,t->tm_mon+1,t->tm_mday);
	snprintf(ThostSettlementInfoConfirmField.ConfirmTime,sizeof(ThostSettlementInfoConfirmField.ConfirmTime),"%02d:%02d:%02d",t->tm_hour,t->tm_min,t->tm_sec);

	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspSettlementInfoConfirm, m_pSpi, &ThostSettlementInfoConfirmField, nullptr, nRequestID, true));
	return 0;	
}

int CFtdcTraderApiImpl::ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryDepthMarketData, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///产品查询
int CFtdcTraderApiImpl::ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID)
{
	m_io_service.post(boost::bind(&CFtdcTraderApiImpl::HandleReqQryProduct, this, *pQryProduct, nRequestID));
	
	return 0;
}

int CFtdcTraderApiImpl::HandleReqQryProduct(CThostFtdcQryProductField QryProduct, int nRequestID)
{
	static CThostFtdcProductField Products[16];
	memset(Products, 0x00, sizeof(Products));

	int i = 0;
	strncpy(Products[i].ExchangeID, EXCHANGE_SH, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_SHStock;
	strncpy(Products[i].ProductName, "上海股票", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SH, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_FUND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SHFund;
	strncpy(Products[i].ProductName, "上海基金", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SH, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_BOND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SHBond;
	strncpy(Products[i].ProductName, "上海债券", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SH, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_BOND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SHStandard;
	strncpy(Products[i].ProductName, "上海标准券", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SH, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_BOND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SHRepurchase;
	strncpy(Products[i].ProductName, "上海质押式回购", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZStock;
	strncpy(Products[i].ProductName, "深圳股票", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_FUND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZFund;
	strncpy(Products[i].ProductName, "深圳基金", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_BOND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZBond;
	strncpy(Products[i].ProductName, "深圳债券", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_BOND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZStandard;
	strncpy(Products[i].ProductName, "深圳标准券", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_BOND;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZRepurchase;
	strncpy(Products[i].ProductName, "深圳质押式回购", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZSEHKMain;
	strncpy(Products[i].ProductName, "深港通港股主板", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZSEHKGEM;
	strncpy(Products[i].ProductName, "深港通港股创业板", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZSEHKETS;
	strncpy(Products[i].ProductName, "深港通港股扩充证券", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SZ, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_SZSEHKNasdaqAMX;
	strncpy(Products[i].ProductName, "深港通港股NasdaqAMX", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_SH, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_SHKC;
	strncpy(Products[i].ProductName, "上海科创板", sizeof(Products[i].ProductName) - 1);

	i++;
	strncpy(Products[i].ExchangeID, EXCHANGE_BSE, sizeof(Products[i].ExchangeID) - 1);
	Products[i].ProductClass = OPENCTP_FTDC_PC_EQUITY;
	Products[i].ProductID[0] = TORA_TSTP_PID_BJStock;
	strncpy(Products[i].ProductName, "北京股票", sizeof(Products[i].ProductName) - 1);

	for (int i = 0; i < sizeof(Products) / sizeof(CThostFtdcProductField); i++) {
		Products[i].VolumeMultiple = 10000;
		Products[i].ExchangeProductID[0] = Products[i].ProductID[0];
		Products[i].PriceTick = 0.0001;
		Products[i].PositionType = THOST_FTDC_PT_Gross;
		Products[i].PositionDateType = THOST_FTDC_PDT_NoUseHistory;
		strncpy(Products[i].TradeCurrencyID, "CNY", sizeof(Products[i].TradeCurrencyID) - 1);
		
		m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryProduct, m_pSpi, &Products[i], nullptr, nRequestID, i == sizeof(Products) / sizeof(CThostFtdcProductField) - 1 ? true : false));
	}
	return 0;
}

int CFtdcTraderApiImpl::ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID)
{
	memset(&BrokerTradingParamsField, 0, sizeof(BrokerTradingParamsField));

	strncpy(BrokerTradingParamsField.BrokerID, m_BrokerID, sizeof(BrokerTradingParamsField.BrokerID)-1);
	strncpy(BrokerTradingParamsField.InvestorID, m_UserID, sizeof(BrokerTradingParamsField.InvestorID) - 1);
	strncpy(BrokerTradingParamsField.CurrencyID, "CNY", sizeof(BrokerTradingParamsField.CurrencyID) - 1);

	BrokerTradingParamsField.MarginPriceType = THOST_FTDC_MPT_OpenPrice;
	BrokerTradingParamsField.OptionRoyaltyPriceType = THOST_FTDC_MPT_OpenPrice;
	BrokerTradingParamsField.Algorithm = THOST_FTDC_AG_OnlyLost;

	memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));

	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryBrokerTradingParams, m_pSpi, &BrokerTradingParamsField, &ThostRspInfo, nRequestID, true));

	return 0;	
}

int CFtdcTraderApiImpl::ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryInvestorPositionDetail, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///询价录入请求
int CFtdcTraderApiImpl::ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID)
{
	m_io_service.post(std::bind(&CThostFtdcTraderSpi::OnRspForQuoteInsert, m_pSpi, pInputForQuote, &ThostRspInfoNotSupported, nRequestID, true));
	return 0;
}

///报价录入请求
int CFtdcTraderApiImpl::ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQuoteInsert, m_pSpi, pInputQuote, &ThostRspInfoNotSupported, nRequestID, true));
	return 0;
}

///报价操作请求
int CFtdcTraderApiImpl::ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQuoteAction, m_pSpi, pInputQuoteAction, &ThostRspInfoNotSupported, nRequestID, true));
	return 0;
}


int CFtdcTraderApiImpl::ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryInvestorPositionCombineDetail, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID)
{
	memset(&SettlementInfoConfirmField, 0, sizeof(SettlementInfoConfirmField));
	strncpy(SettlementInfoConfirmField.BrokerID, m_BrokerID, sizeof(SettlementInfoConfirmField.BrokerID)-1);
	strncpy(SettlementInfoConfirmField.InvestorID, m_InvestorID, sizeof(SettlementInfoConfirmField.InvestorID) - 1);
	struct tm* t;
	time_t tt;
	tt = time(NULL);
	t = localtime(&tt);
	snprintf(SettlementInfoConfirmField.ConfirmDate, sizeof(SettlementInfoConfirmField.ConfirmDate), "%04d%02d%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	snprintf(SettlementInfoConfirmField.ConfirmTime, sizeof(SettlementInfoConfirmField.ConfirmTime), "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);

	memset(&ThostRspInfo, 0x00, sizeof(ThostRspInfo));
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySettlementInfoConfirm, m_pSpi, &SettlementInfoConfirmField, &ThostRspInfo, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID)
{
	return ReqQrySettlementInfoConfirm(NULL, nRequestID);
}

 int CFtdcTraderApiImpl::ReqQryProductGroup(CThostFtdcQryProductGroupField *pQryProductGroup, int nRequestID)
 {
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryProductGroup, m_pSpi, nullptr, nullptr, nRequestID, true));
 	return 0;
 }

int CFtdcTraderApiImpl::ReqQryTransferSerial(CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryTransferSerial, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQryTransferBank(CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryTransferBank, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryForQuote, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
};

int CFtdcTraderApiImpl::ReqQryNotice(CThostFtdcQryNoticeField *pQryNotice, int nRequestID)
{	
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryNotice,m_pSpi,nullptr, nullptr, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqAuthenticate(CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID)
{
	m_io_service.post(boost::bind(&CFtdcTraderApiImpl::HandleReqAuthenticate, this, *pReqAuthenticateField, nRequestID));
	return 0;
}
void CFtdcTraderApiImpl::HandleReqAuthenticate(CThostFtdcReqAuthenticateField& AuthenticateField, int nRequestID)
{
	memset(&RspAuthenticateField, 0x00, sizeof(RspAuthenticateField));
	strncpy(RspAuthenticateField.BrokerID, AuthenticateField.BrokerID, sizeof(RspAuthenticateField.BrokerID) - 1);
	strncpy(RspAuthenticateField.UserID, AuthenticateField.UserID, sizeof(RspAuthenticateField.UserID) - 1);
	strncpy(RspAuthenticateField.UserProductInfo, AuthenticateField.UserProductInfo, sizeof(RspAuthenticateField.UserProductInfo) - 1);
	memset(&ThostRspInfo, 0x00, sizeof(ThostRspInfo));
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspAuthenticate, m_pSpi, &RspAuthenticateField, &ThostRspInfo, nRequestID, true));
}

int CFtdcTraderApiImpl::ReqQryAccountregister(CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryAccountregister, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQryContractBank(CThostFtdcQryContractBankField *pQryContractBank, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryContractBank, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *pQryContractBank, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryTradingNotice, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

void CFtdcTraderApiImpl::OnFrontConnected()
{
	if(m_pSpi)
		m_pSpi->OnFrontConnected();
}

void CFtdcTraderApiImpl::OnFrontDisconnected(int nReason)
{
	if(m_pSpi)
		m_pSpi->OnFrontDisconnected(0);
}
		
void CFtdcTraderApiImpl::OnRspError(CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(m_pSpi)
	{
		CThostFtdcRspInfoField *pThostRspInfo = nullptr;
		if(pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(&ThostRspInfo.ErrorIDpRspInfo,pRspInfo->ErrorMsg,sizeof(ThostRspInfo.ErrorIDpRspInfo)-1);
			pThostRspInfo = &ThostRspInfo;
		}
		m_pSpi->OnRspError(pThostRspInfo, nRequestID, bool bIsLast);
	}
}

///用户登录应答
void CFtdcTraderApiImpl::OnRspUserLogin(CTORATstpRspUserLoginField *pRspUserLoginField, CTORATstpRspInfoField *pRspInfo, int nRequestID)
{
	if(m_pSpi)
	{
		CThostFtdcRspUserLoginField*  pThostRspUserLogin=NULL;
					
		if(pRspUserLoginField)
		{
			memset(&ThostRspUserLogin,0,sizeof(ThostRspUserLogin));
			strncpy(ThostRspUserLogin.TradingDay, TradingDay, sizeof(ThostRspUserLogin.TradingDay)-1);
			strncpy(ThostRspUserLogin.BrokerID,pRspUserLoginField->DepartmentID, sizeof(ThostRspUserLogin.BrokerID) - 1);
			strncpy(ThostRspUserLogin.UserID,m_UserID, sizeof(ThostRspUserLogin.UserID) - 1);
			ThostRspUserLogin.FrontID = pRspUserLoginField->FrontID;
			ThostRspUserLogin.SessionID=pRspUserLoginField->SessionID;
			snprintf(ThostRspUserLogin.MaxOrderRef, sizeof(ThostRspUserLogin.MaxOrderRef), "%d", pRspUserLoginField->MaxOrderRef+1);
			strncpy(ThostRspUserLogin.TradingDay, pRspUserLoginField->TradingDay, sizeof(ThostRspUserLogin.TradingDay) - 1);
			strncpy(ThostRspUserLogin.SystemName, pRspUserLoginField->SystemName, sizeof(ThostRspUserLogin.SystemName) - 1);
			strncpy(ThostRspUserLogin.CZCETime,pRspUserLoginField->LoginTime, sizeof(ThostRspUserLogin.CZCETime) - 1);
			strncpy(ThostRspUserLogin.SHFETime,pRspUserLoginField->LoginTime, sizeof(ThostRspUserLogin.SHFETime) - 1);
			strncpy(ThostRspUserLogin.DCETime,pRspUserLoginField->LoginTime, sizeof(ThostRspUserLogin.DCETime) - 1);
			strncpy(ThostRspUserLogin.FFEXTime,pRspUserLoginField->LoginTime, sizeof(ThostRspUserLogin.FFEXTime) - 1);
			strncpy(ThostRspUserLogin.INETime,pRspUserLoginField->LoginTime, sizeof(ThostRspUserLogin.INETime) - 1);
			m_FrontID = ThostRspUserLogin.FrontID;
			m_SessionID = ThostRspUserLogin.SessionID;
			pThostRspUserLogin = &ThostRspUserLogin;
		}
	
		if(pRspInfo)
		{
			memset(&ThostRspInfo,0,sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg,pRspInfo->ErrorMsg,sizeof(ThostRspInfo.ErrorMsg) - 1);
		}

		// 查询股东账号
		CTORATstpQryShareholderAccountField Req;
		memset(&Req, 0x00, sizeof(Req));
		m_pUserApi->ReqQryShareholderAccount(&Req, 0);

		m_pSpi->OnRspUserLogin(pThostRspUserLogin, &ThostRspInfo, nRequestID, true);
	}
}

///用户退出应答
void CFtdcTraderApiImpl::OnRspUserLogout(CTORATstpUserLogoutField *pUserLogoutField, CTORATstpRspInfoField *pRspInfo, int nRequestID)
{
	if(m_pSpi)
	{
		CThostFtdcUserLogoutField*  pThostRspUserLogout=NULL;
		CThostFtdcUserLogoutField  ThostRspUserLogout;			
		
		if(pUserLogoutField)
		{
			memset(&ThostRspUserLogout,0,sizeof(ThostRspUserLogout));
			strncpy(ThostRspUserLogout.UserID,m_UserID,sizeof(ThostRspUserLogout.UserID)-1);
			pThostRspUserLogout = &ThostRspUserLogout;
		}

		CThostFtdcRspInfoField*  pThostRspInfo=NULL;
		CThostFtdcRspInfoField  ThostRspInfo;	
					
		if(pRspInfo)
		{
			memset(&ThostRspInfo,0,sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg,pRspInfo->ErrorMsg,sizeof(ThostRspInfo.ErrorMsg)-1);
			pThostRspInfo = &ThostRspInfo;
		}
		m_pSpi->OnRspUserLogout(pThostRspUserLogout, pThostRspInfo, nRequestID, true);
	}
}

///用户密码修改应答
void CFtdcTraderApiImpl::OnRspUserPasswordUpdate(CTORATstpUserPasswordUpdateField *pUserPasswordUpdateField, CTORATstpRspInfoField *pRspInfo, int nRequestID)
{
	if(m_pSpi != NULL)
	{
		CThostFtdcUserPasswordUpdateField*  pThostUserPasswordUpdate=NULL;
		CThostFtdcUserPasswordUpdateField  ThostUserPasswordUpdate;	
		
			
		if(pUserPasswordUpdateField)
		{
			memset(&ThostUserPasswordUpdate,0,sizeof(ThostUserPasswordUpdate));
			strncpy(ThostUserPasswordUpdate.UserID, m_UserID,sizeof(ThostUserPasswordUpdate.UserID)-1);
			strncpy(ThostUserPasswordUpdate.OldPassword, pUserPasswordUpdateField->OldPassword,sizeof(ThostUserPasswordUpdate.OldPassword)-1);
			strncpy(ThostUserPasswordUpdate.NewPassword, pUserPasswordUpdateField->NewPassword,sizeof(ThostUserPasswordUpdate.NewPassword)-1);
			pThostUserPasswordUpdate = &ThostUserPasswordUpdate;
		}

		CThostFtdcRspInfoField*  pThostRspInfo=NULL;
		CThostFtdcRspInfoField  ThostRspInfo;	
			
		if(NULL!=pRspInfo)
		{
			memset(&ThostRspInfo,0,sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg,pRspInfo->ErrorMsg,sizeof(ThostRspInfo.ErrorMsg)-1);
			pThostRspInfo = &ThostRspInfo;
		}
		m_pSpi->OnRspUserPasswordUpdate(pThostUserPasswordUpdate, pThostRspInfo, nRequestID, true);
	}
}



///合约查询应答
void CFtdcTraderApiImpl::OnRspQrySecurity(CTORATstpSecurityField *pSecurity, CTORATstpRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(m_pSpi)
	{
		CThostFtdcInstrumentField*  pThostInstrument=NULL;
		CThostFtdcInstrumentField  ThostInstrument;	
		if(pSecurity)
		{		
			memset(&ThostInstrument,0,sizeof(ThostInstrument));
			if (pSecurity->ExchangeID == TORA_TSTP_EXD_SSE)
				strncpy(ThostInstrument.ExchangeID, EXCHANGE_SH, sizeof(ThostInstrument.ExchangeID) - 1);
			else if (pSecurity->ExchangeID == TORA_TSTP_EXD_SZSE)
				strncpy(ThostInstrument.ExchangeID, EXCHANGE_SZ, sizeof(ThostInstrument.ExchangeID) - 1);
			else if (pSecurity->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostInstrument.ExchangeID, EXCHANGE_BSE, sizeof(ThostInstrument.ExchangeID) - 1);
			else if (pSecurity->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostInstrument.ExchangeID, EXCHANGE_HKEX, sizeof(ThostInstrument.ExchangeID) - 1);
			strncpy(ThostInstrument.InstrumentID,pSecurity->SecurityID,sizeof(ThostInstrument.InstrumentID)-1);
			strncpy(ThostInstrument.ExchangeInstID,pSecurity->SecurityID,sizeof(ThostInstrument.ExchangeInstID)-1);
			strncpy(ThostInstrument.InstrumentName,pSecurity->SecurityName,sizeof(ThostInstrument.InstrumentName)-1);
			ThostInstrument.ProductID[0] = pSecurity->ProductID;
			ThostInstrument.VolumeMultiple = pSecurity->VolumeMultiple;
			ThostInstrument.PriceTick = pSecurity->PriceTick;
			ThostInstrument.IsTrading = true;
			ThostInstrument.PositionType = THOST_FTDC_PT_Net;
			ThostInstrument.PositionDateType = THOST_FTDC_PDT_UseHistory;
			ThostInstrument.OptionsType = THOST_FTDC_CP_CallOptions;
			strncpy(ThostInstrument.OpenDate, pSecurity->OpenDate, sizeof(ThostInstrument.OpenDate) - 1);
			strncpy(ThostInstrument.CreateDate, pSecurity->OpenDate, sizeof(ThostInstrument.CreateDate) - 1);
			// 类型
			switch (pSecurity->ProductID) {
			case TORA_TSTP_PID_SHStock: // 上海股票
			case TORA_TSTP_PID_SZStock: // 深圳股票
			case TORA_TSTP_PID_SZSEHKMain: // 深港通港股主板
			case TORA_TSTP_PID_SHKC: // 上海科创板
			case TORA_TSTP_PID_SZSEHKNasdaqAMX: // 深港通港股NasdaqAMX市场
			case TORA_TSTP_PID_SZSEHKGEM: // 深港通港股创业板
			case TORA_TSTP_PID_SZSEHKETS: // 深港通港股扩充交易证券
				ThostInstrument.ProductClass = OPENCTP_FTDC_PC_EQUITY;
				break;
			case TORA_TSTP_PID_SHBond: // 上海债券
			case TORA_TSTP_PID_SHStandard: // 上海标准券
			case TORA_TSTP_PID_SHRepurchase: // 上海质押式回购
			case TORA_TSTP_PID_SZBond: // 深圳债券
			case TORA_TSTP_PID_SZStandard: // 深圳标准券
			case TORA_TSTP_PID_SZRepurchase: // 深圳质押式回购
				ThostInstrument.ProductClass = OPENCTP_FTDC_PC_BOND; // 债券
				break;
			case TORA_TSTP_PID_SHFund: // 上海基金
			case TORA_TSTP_PID_SZFund: // 深圳基金
				ThostInstrument.ProductClass = OPENCTP_FTDC_PC_FUND; // 基金
				break;
			default:
				ThostInstrument.ProductClass = OPENCTP_FTDC_PC_EQUITY;
				break;
			}
			ThostInstrument.InstLifePhase = THOST_FTDC_IP_Started;
			ThostInstrument.MaxMarginSideAlgorithm=THOST_FTDC_MMSA_NO;			
			ThostInstrument.CombinationType = THOST_FTDC_COMBT_Future;
			ThostInstrument.LongMarginRatio = 1.0;
			ThostInstrument.ShortMarginRatio = 1.0;
			strcpy(ThostInstrument.OpenDate, pSecurity->OpenDate);
			ThostInstrument.MaxLimitOrderVolume = pSecurity->MaxLimitOrderBuyVolume;
			ThostInstrument.MinLimitOrderVolume = pSecurity->MinLimitOrderBuyVolume;
			ThostInstrument.MaxMarketOrderVolume = pSecurity->MaxMarketOrderBuyVolume;
			ThostInstrument.MinMarketOrderVolume = pSecurity->MinMarketOrderBuyVolume;
			pThostInstrument = &ThostInstrument;
		}
		CThostFtdcRspInfoField*  pThostRspInfo=NULL;
		CThostFtdcRspInfoField  ThostRspInfo;
		if(NULL!=pRspInfo)
		{			
			memset(&ThostRspInfo,0,sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg,pRspInfo->ErrorMsg,sizeof(ThostRspInfo.ErrorMsg)-1);
			pThostRspInfo = &ThostRspInfo;
		}
		
		m_pSpi->OnRspQryInstrument(pThostInstrument, pThostRspInfo, nRequestID, bIsLast);
	}
}

//投资者持仓查询
void CFtdcTraderApiImpl::OnRspQryPosition(CTORATstpPositionField* pPosition, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (m_pSpi)
	{
		CThostFtdcRspInfoField* pThostRspInfo = NULL;
		CThostFtdcRspInfoField  ThostRspInfo;

		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}

		CThostFtdcInvestorPositionField* pThostRspInvestorPosition = NULL;
		CThostFtdcInvestorPositionField  ThostRspInvestorPosition;

		if (pPosition)
		{
			memset(&ThostRspInvestorPosition, 0, sizeof(ThostRspInvestorPosition));
			strncpy(ThostRspInvestorPosition.BrokerID, m_BrokerID, sizeof(ThostRspInvestorPosition.BrokerID) - 1);
			strncpy(ThostRspInvestorPosition.InvestorID, m_UserID, sizeof(ThostRspInvestorPosition.InvestorID) - 1);
			if(pPosition->ExchangeID== TORA_TSTP_EXD_SSE)
				strncpy(ThostRspInvestorPosition.ExchangeID, EXCHANGE_SH, sizeof(ThostRspInvestorPosition.ExchangeID) - 1);
			else if(pPosition->ExchangeID== TORA_TSTP_EXD_SZSE)
				strncpy(ThostRspInvestorPosition.ExchangeID, EXCHANGE_SZ, sizeof(ThostRspInvestorPosition.ExchangeID) - 1);
			else if (pPosition->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostRspInvestorPosition.ExchangeID, EXCHANGE_BSE, sizeof(ThostRspInvestorPosition.ExchangeID) - 1);
			else if (pPosition->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostRspInvestorPosition.ExchangeID, EXCHANGE_HKEX, sizeof(ThostRspInvestorPosition.ExchangeID) - 1);

			strncpy(ThostRspInvestorPosition.InstrumentID, pPosition->SecurityID, sizeof(ThostRspInvestorPosition.InstrumentID) - 1);
			strncpy(ThostRspInvestorPosition.TradingDay, TradingDay, sizeof(ThostRspInvestorPosition.TradingDay) - 1);
			ThostRspInvestorPosition.HedgeFlag = THOST_FTDC_HF_Speculation;
			ThostRspInvestorPosition.UseMargin = 0;
			ThostRspInvestorPosition.FrozenMargin = 0;

			//上海期货交易所的持仓有两条，分为昨持仓和今持仓
			ThostRspInvestorPosition.PosiDirection = THOST_FTDC_PD_Long; // A股只有多仓
			ThostRspInvestorPosition.Position = pPosition->CurrentPosition;
			ThostRspInvestorPosition.PositionCost = pPosition->TotalPosCost;
			ThostRspInvestorPosition.YdPosition = pPosition->PrePosition;
			ThostRspInvestorPosition.LongFrozen = 0;
			ThostRspInvestorPosition.ShortFrozen = pPosition->HistoryPosFrozen;
			ThostRspInvestorPosition.PositionDate = THOST_FTDC_PSD_Today;
			ThostRspInvestorPosition.OpenVolume = 0;
			ThostRspInvestorPosition.CloseVolume = 0;
			ThostRspInvestorPosition.OpenCost = pPosition->OpenPosCost;
			ThostRspInvestorPosition.PositionProfit = 0;
			ThostRspInvestorPosition.CloseProfit = 0;
			ThostRspInvestorPosition.TodayPosition = pPosition->CurrentPosition - pPosition->HistoryPos;
			m_pSpi->OnRspQryInvestorPosition(&ThostRspInvestorPosition, pThostRspInfo, nRequestID, bIsLast);
		}
		else {
			m_pSpi->OnRspQryInvestorPosition(pThostRspInvestorPosition, pThostRspInfo, nRequestID, bIsLast);
		}
	}
}

//报单查询
void CFtdcTraderApiImpl::OnRspQryOrder(CTORATstpOrderField* pOrder, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (m_pSpi)
	{
		CThostFtdcOrderField* pThostOrder = NULL;
		CThostFtdcOrderField  ThostOrder;
		if (pOrder)
		{
			memset(&ThostOrder, 0x00, sizeof(ThostOrder));
			strncpy(ThostOrder.UserID, m_UserID, sizeof(ThostOrder.UserID) - 1);
			strncpy(ThostOrder.AccountID, pOrder->AccountID, sizeof(ThostOrder.AccountID) - 1);
			strncpy(ThostOrder.InvestorID, pOrder->InvestorID, sizeof(ThostOrder.InvestorID) - 1);
			strncpy(ThostOrder.InstrumentID, pOrder->SecurityID, sizeof(ThostOrder.InstrumentID) - 1);
			if (pOrder->ExchangeID == TORA_TSTP_EXD_SSE)
				strncpy(ThostOrder.ExchangeID, EXCHANGE_SH, sizeof(ThostOrder.ExchangeID) - 1);
			else if (pOrder->ExchangeID == TORA_TSTP_EXD_SZSE)
				strncpy(ThostOrder.ExchangeID, EXCHANGE_SZ, sizeof(ThostOrder.ExchangeID) - 1);
			else if (pOrder->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostOrder.ExchangeID, EXCHANGE_BSE, sizeof(ThostOrder.ExchangeID) - 1);
			else if (pOrder->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostOrder.ExchangeID, EXCHANGE_HKEX, sizeof(ThostOrder.ExchangeID) - 1);
			ThostOrder.VolumeTotal = pOrder->VolumeTotalOriginal - pOrder->VolumeTraded;
			ThostOrder.VolumeTotalOriginal = pOrder->VolumeTotalOriginal;
			ThostOrder.VolumeTraded = pOrder->VolumeTraded;
			ThostOrder.LimitPrice = pOrder->LimitPrice;
			
			switch (pOrder->OrderPriceType) {
			case TORA_TSTP_OPT_AnyPrice:
				ThostOrder.OrderPriceType = THOST_FTDC_OPT_AnyPrice;
				break;
			case TORA_TSTP_OPT_LimitPrice:
				ThostOrder.OrderPriceType = THOST_FTDC_OPT_LimitPrice;
				break;
			case TORA_TSTP_OPT_BestPrice:
				ThostOrder.OrderPriceType = THOST_FTDC_OPT_BestPrice;
				break;
			default:
				break;
			}

			ThostOrder.Direction = pOrder->Direction == TORA_TSTP_D_Buy ? THOST_FTDC_D_Buy : THOST_FTDC_D_Sell;
			ThostOrder.CombOffsetFlag[0] = pOrder->Direction == TORA_TSTP_D_Buy ? THOST_FTDC_OF_Open : THOST_FTDC_OF_Close;
			ThostOrder.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
			ThostOrder.FrontID = pOrder->FrontID;
			ThostOrder.SessionID = pOrder->SessionID;
			snprintf(ThostOrder.OrderRef, sizeof(ThostOrder.OrderRef), "%d", pOrder->OrderRef);
			strncpy(ThostOrder.OrderSysID, pOrder->OrderSysID, sizeof(ThostOrder.OrderSysID) - 1);

			switch (pOrder->TimeCondition) {
			case TORA_TSTP_TC_IOC:
				ThostOrder.TimeCondition = THOST_FTDC_TC_IOC;
				break;
			case TORA_TSTP_TC_GFS:
				ThostOrder.TimeCondition = THOST_FTDC_TC_GFS;
				break;
			case TORA_TSTP_TC_GFD:
				ThostOrder.TimeCondition = THOST_FTDC_TC_GFD;
				break;
			case TORA_TSTP_TC_GTD:
				ThostOrder.TimeCondition = THOST_FTDC_TC_GTD;
				break;
			case TORA_TSTP_TC_GTC:
				ThostOrder.TimeCondition = THOST_FTDC_TC_GTC;
				break;
			case TORA_TSTP_TC_GFA:
				ThostOrder.TimeCondition = THOST_FTDC_TC_GFA;
				break;
			default:
				break;
			}

			switch (pOrder->OrderStatus)
			{
			case TORA_TSTP_OST_Unknown:
				ThostOrder.OrderStatus = THOST_FTDC_OST_Unknown;
				break;
			case TORA_TSTP_OST_AllTraded:
				ThostOrder.OrderStatus = THOST_FTDC_OST_AllTraded;
				break;
			case TORA_TSTP_OST_PartTraded:
				ThostOrder.OrderStatus = THOST_FTDC_OST_PartTradedQueueing;
				break;
			case TORA_TSTP_OST_PartTradeCanceled:
			case TORA_TSTP_OST_AllCanceled:
			case TORA_TSTP_OST_Rejected:
				ThostOrder.OrderStatus = THOST_FTDC_OST_Canceled;
				break;
			default:
				ThostOrder.OrderStatus = THOST_FTDC_OST_NoTradeQueueing;
				break;
			}

			strncpy(ThostOrder.StatusMsg, pOrder->StatusMsg, sizeof(ThostOrder.StatusMsg) - 1);
			ThostOrder.OrderSubmitStatus = pOrder->OrderSubmitStatus;
			strncpy(ThostOrder.InsertDate, pOrder->InsertDate, sizeof(ThostOrder.InsertDate) - 1);
			strncpy(ThostOrder.InsertTime, pOrder->InsertTime, sizeof(ThostOrder.InsertTime) - 1);
			strncpy(ThostOrder.CancelTime, pOrder->CancelTime, sizeof(ThostOrder.CancelTime) - 1);
			strncpy(ThostOrder.ActiveUserID, m_UserID, sizeof(ThostOrder.ActiveUserID) - 1);
			strncpy(ThostOrder.OrderLocalID, pOrder->OrderLocalID, sizeof(ThostOrder.OrderLocalID) - 1);
			strncpy(ThostOrder.ClientID, pOrder->ShareholderID, sizeof(ThostOrder.ClientID) - 1);
			strncpy(ThostOrder.InvestUnitID, pOrder->BusinessUnitID, sizeof(ThostOrder.InvestUnitID) - 1);
			pThostOrder = &ThostOrder;
		}
		CThostFtdcRspInfoField* pThostRspInfo = NULL;
		CThostFtdcRspInfoField  ThostRspInfo;
		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}
		m_pSpi->OnRspQryOrder(pThostOrder, pThostRspInfo, nRequestID, bIsLast);
	}
}


//成交查询
void CFtdcTraderApiImpl::OnRspQryTrade(CTORATstpTradeField* pTrade, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (m_pSpi)
	{
		CThostFtdcTradeField* pThostTrade = NULL;
		CThostFtdcTradeField  ThostTrade;
		if (pTrade)
		{
			memset(&ThostTrade, 0, sizeof(ThostTrade));
			strncpy(ThostTrade.BrokerID, m_BrokerID, sizeof(ThostTrade.BrokerID) - 1);
			strncpy(ThostTrade.UserID, m_UserID, sizeof(ThostTrade.UserID) - 1);
			strncpy(ThostTrade.InvestorID, pTrade->InvestorID, sizeof(ThostTrade.InvestorID) - 1);
			if (pTrade->ExchangeID == TORA_TSTP_EXD_SSE)
				strncpy(ThostTrade.ExchangeID, EXCHANGE_SH, sizeof(ThostTrade.ExchangeID) - 1);
			else if (pTrade->ExchangeID == TORA_TSTP_EXD_SZSE)
				strncpy(ThostTrade.ExchangeID, EXCHANGE_SZ, sizeof(ThostTrade.ExchangeID) - 1);
			else if (pTrade->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostTrade.ExchangeID, EXCHANGE_BSE, sizeof(ThostTrade.ExchangeID) - 1);
			else if (pTrade->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostTrade.ExchangeID, EXCHANGE_HKEX, sizeof(ThostTrade.ExchangeID) - 1);
			strncpy(ThostTrade.InstrumentID, pTrade->SecurityID, sizeof(ThostTrade.InstrumentID) - 1);
			strncpy(ThostTrade.TradeID, pTrade->TradeID, sizeof(ThostTrade.TradeID) - 1);
			strncpy(ThostTrade.OrderSysID, pTrade->OrderSysID, sizeof(ThostTrade.OrderSysID) - 1);
			ThostTrade.Direction = pTrade->Direction == TORA_TSTP_D_Buy ? THOST_FTDC_D_Buy : THOST_FTDC_D_Sell;
			ThostTrade.OffsetFlag = pTrade->Direction == TORA_TSTP_D_Buy ? THOST_FTDC_OF_Open : THOST_FTDC_OF_Close;
			ThostTrade.HedgeFlag = THOST_FTDC_HF_Speculation;
			ThostTrade.Price = pTrade->Price;
			ThostTrade.Volume = pTrade->Volume;
			snprintf(ThostTrade.OrderRef, sizeof(ThostTrade.OrderRef), "%d", pTrade->OrderRef);
			strncpy(ThostTrade.OrderLocalID, pTrade->OrderLocalID, sizeof(ThostTrade.OrderLocalID) - 1);
			strncpy(ThostTrade.TradeDate, pTrade->TradeDate, sizeof(ThostTrade.TradeDate) - 1);
			strncpy(ThostTrade.TradeTime, pTrade->TradeTime, sizeof(ThostTrade.TradeTime) - 1);
			strncpy(ThostTrade.TradingDay, TradingDay, sizeof(ThostTrade.TradingDay) - 1);
			ThostTrade.TradeType = THOST_FTDC_TRDT_Common;
			strncpy(ThostTrade.ClientID, pTrade->ShareholderID, sizeof(ThostTrade.ClientID) - 1);
			strncpy(ThostTrade.InvestUnitID, pTrade->BusinessUnitID, sizeof(ThostTrade.InvestUnitID) - 1);
			pThostTrade = &ThostTrade;
		}

		CThostFtdcRspInfoField* pThostRspInfo = NULL;
		CThostFtdcRspInfoField  ThostRspInfo;
		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}
		m_pSpi->OnRspQryTrade(pThostTrade, pThostRspInfo, nRequestID, bIsLast);
	}
}

//报单回报
void CFtdcTraderApiImpl::OnRtnOrder(CUTOrderField *pOrder)
{
	if (m_pSpi) {
		CThostFtdcOrderField Order = {};
		strncpy(Order.BrokerID, m_BrokerID, sizeof(Order.BrokerID) - 1);
		strncpy(Order.UserID, m_UserID,sizeof(Order.UserID)-1);
		strncpy(Order.AccountID, pOrder->BranchID, sizeof(Order.AccountID) - 1);
		strncpy(Order.InvestorID, pOrder->InvestorID, sizeof(Order.InvestorID) - 1);
		strncpy(Order.InstrumentID, pOrder->InstrumentID, sizeof(Order.InstrumentID) - 1);

		switch (pOrder->ExchangeID)
		{
		case UT_EXG_SSE:
			strncpy(Order.ExchangeID, EXCHANGE_SH, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_SZSE:
			strncpy(Order.ExchangeID, EXCHANGE_SZ, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_SHFE:
			strncpy(Order.ExchangeID, EXCHANGE_SHFE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_DCE:
			strncpy(Order.ExchangeID, EXCHANGE_DCE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_CZCE:
			strncpy(Order.ExchangeID, EXCHANGE_CZCE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_INE:
			strncpy(Order.ExchangeID, EXCHANGE_INE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_HKEX:
			strncpy(Order.ExchangeID, EXCHANGE_HKEX, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_HKEX:
			strncpy(Order.ExchangeID, EXCHANGE_HKEX, sizeof(Order.ExchangeID) - 1);
			break;
		default:	// 无北交所 暂不处理
			break;
		}
		Order.VolumeTotal = pOrder->VolumeTotalOriginal - pOrder->VolumeTraded;
		Order.VolumeTotalOriginal = pOrder->VolumeTotalOriginal;
		Order.VolumeTraded = pOrder->VolumeTraded;
		Order.LimitPrice = pOrder->LimitPrice;
		Order.OrderPriceType = pOrder->OrderPriceType;
		Order.Direction = pOrder->Direction;
		Order.CombOffsetFlag[0] = pOrder->OffsetFlag;
		Order.CombHedgeFlag[0] = pOrder->HedgeFlag;
		Order.FrontID = pOrder->FrontID;
		Order.SessionID = pOrder->SessionID;
		strncpy(Order.OrderRef,pOrder->OrderRef, sizeof(Order.OrderRef) - 1);
		strncpy(Order.OrderSysID, pOrder->OrderSysID, sizeof(Order.OrderSysID) - 1);
		strncpy(Order.InvestUnitID, pOrder->UserProductInfo, sizeof(Order.InvestUnitID) - 1);
		Order.TimeCondition = pOrder->TimeCondition;
		Order.OrderStatus = pOrder->OrderStatus;
		strncpy(Order.StatusMsg, pOrder->StatusMsg, sizeof(Order.StatusMsg) - 1);
		Order.OrderSubmitStatus = pOrder->OrderSubmitStatus;
		strncpy(Order.InsertDate, pOrder->InsertDate, sizeof(Order.InsertDate) - 1);
		strncpy(Order.InsertTime, pOrder->InsertTime, sizeof(Order.InsertTime) - 1);
		strncpy(Order.CancelTime, pOrder->CancelTime, sizeof(Order.CancelTime) - 1);
		strncpy(Order.ActiveUserID, m_UserID, sizeof(Order.ActiveUserID) - 1);
		strncpy(Order.OrderLocalID, pOrder->OrderLocalID, sizeof(Order.OrderLocalID) - 1);
		strncpy(Order.ClientID, pOrder->ClientID, sizeof(Order.ClientID) - 1);

		m_pSpi->OnRtnOrder(&Order);
	}	
}

//成交回报
void CFtdcTraderApiImpl::OnRtnTrade(CUTTradeField *pTrade)
{
	if (m_pSpi)
	{
		CThostFtdcTradeField  ThostTrade = {};
		strncpy(ThostTrade.BrokerID, m_BrokerID, sizeof(ThostTrade.BrokerID) - 1);
		strncpy(ThostTrade.UserID, m_UserID, sizeof(ThostTrade.UserID) - 1);
		strncpy(ThostTrade.InvestorID, pTrade->InvestorID, sizeof(ThostTrade.InvestorID) - 1);
		switch (pTrade->ExchangeID)
		{
		case UT_EXG_SSE:
			strncpy(Order.ExchangeID, EXCHANGE_SH, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_SZSE:
			strncpy(Order.ExchangeID, EXCHANGE_SZ, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_SHFE:
			strncpy(Order.ExchangeID, EXCHANGE_SHFE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_DCE:
			strncpy(Order.ExchangeID, EXCHANGE_DCE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_CZCE:
			strncpy(Order.ExchangeID, EXCHANGE_CZCE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_INE:
			strncpy(Order.ExchangeID, EXCHANGE_INE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_HKEX:
			strncpy(Order.ExchangeID, EXCHANGE_HKEX, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_HKEX:
			strncpy(Order.ExchangeID, EXCHANGE_HKEX, sizeof(Order.ExchangeID) - 1);
			break;
		default:	// 无北交所 暂不处理
			break;
		}
			
		strncpy(ThostTrade.InstrumentID, pTrade->InstrumentID, sizeof(ThostTrade.InstrumentID) - 1);
		strncpy(ThostTrade.TradeID, pTrade->TradeID, sizeof(ThostTrade.TradeID) - 1);
		strncpy(ThostTrade.OrderSysID, pTrade->OrderSysID, sizeof(ThostTrade.OrderSysID) - 1);
		ThostTrade.Direction = pTrade->Direction;
		ThostTrade.OffsetFlag = pTrade->OffsetFlag;
		ThostTrade.HedgeFlag = pOrder->HedgeFlag;
		ThostTrade.Price = pTrade->Price;
		ThostTrade.Volume = pTrade->Volume;
		snprintf(ThostTrade.OrderRef, sizeof(ThostTrade.OrderRef), "%d", pTrade->OrderRef);
		strncpy(ThostTrade.OrderLocalID, pTrade->OrderLocalID, sizeof(ThostTrade.OrderLocalID) - 1);
		snprintf(ThostTrade.TradeDate, sizeof(ThostTrade.TradeDate), "%d",pTrade->TradeDate);
		snprintf(ThostTrade.TradeTime, sizeof(ThostTrade.TradeTime), "%d",pTrade->TradeTime);
		strncpy(ThostTrade.TradingDay, TradingDay, sizeof(ThostTrade.TradingDay) - 1);
		ThostTrade.TradeType =  pTrade->TradeType;
		strncpy(ThostTrade.ClientID, pTrade->ClientID, sizeof(ThostTrade.ClientID) - 1);
		strncpy(ThostTrade.InvestUnitID, pTrade->UserProductInfo, sizeof(ThostTrade.InvestUnitID) - 1);

		m_pSpi->OnRtnTrade(&ThostTrade);
	}
}

//报单操作回报
void CFtdcTraderApiImpl::OnErrRtnOrderAction(CUTOrderActionField *pOrderAction)
{
	if (m_pSpi)
	{
		CThostFtdcOrderActionField ThostOrderAction = {};
		strncpy(ThostOrderAction.BrokerID, m_BrokerID, sizeof(ThostOrderAction.BrokerID) - 1);
		strncpy(ThostOrderAction.UserID, m_UserID, sizeof(ThostOrderAction.UserID) - 1);
		strncpy(ThostOrderAction.InvestorID, pOrderAction->InvestorID, sizeof(ThostOrderAction.InvestorID) - 1);
		ThostOrderAction.OrderActionRef = pOrderAction->OrderActionRef;
		snprintf(ThostOrderAction.OrderRef, sizeof(ThostOrderAction.OrderRef), "%d",pOrderAction->OrderRef);
		ThostOrderAction.RequestID = 0;
		ThostOrderAction.FrontID = pOrderAction->FrontID;
		ThostOrderAction.SessionID = pOrderAction->SessionID;
		switch (pOrderAction->ExchangeID)
		{
		case UT_EXG_SSE:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_SH, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_SZSE:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_SZ, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_SHFE:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_SHFE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_DCE:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_DCE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_CZCE:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_CZCE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_INE:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_INE, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_HKEX:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_HKEX, sizeof(Order.ExchangeID) - 1);
			break;
		case UT_EXG_HKEX:
			strncpy(ThostOrderAction.ExchangeID, EXCHANGE_HKEX, sizeof(Order.ExchangeID) - 1);
			break;
		default:	// 无北交所 暂不处理
			break;
		}
		strncpy(ThostOrderAction.OrderSysID, pOrderAction->OrderSysID, sizeof(ThostOrderAction.OrderSysID) - 1);
		ThostOrderAction.ActionFlag = pOrderAction->ActionFlag;
		ThostOrderAction.LimitPrice = pOrderAction->LimitPrice;
		ThostOrderAction.VolumeChange = pOrderAction->VolumeChange;
		snprintf(ThostOrderAction.ActionDate, sizeof(ThostOrderAction.ActionDate), "%d",pOrderAction->ActionDate);
		snprintf(ThostOrderAction.ActionTime, sizeof(ThostOrderAction.ActionTime), "%d",pOrderAction->ActionTime);
		strncpy(ThostOrderAction.TraderID, pOrderAction->TraderID, sizeof(ThostOrderAction.TraderID) - 1);
		ThostOrderAction.InstallID = pOrderAction->InstallID;
		strncpy(ThostOrderAction.OrderLocalID, pOrderAction->OrderLocalID, sizeof(ThostOrderAction.OrderLocalID) - 1);
		strncpy(ThostOrderAction.ActionLocalID, pOrderAction->ActionLocalID, sizeof(ThostOrderAction.ActionLocalID) - 1);
		strncpy(ThostOrderAction.ParticipantID, pOrderAction->ParticipantID, sizeof(ThostOrderAction.ParticipantID) - 1);
		strncpy(ThostOrderAction.ClientID, pOrderAction->ClientID, sizeof(ThostOrderAction.ClientID) - 1);
		//strncpy(ThostOrderAction.BusinessUnit, pOrderAction->BusinessUnit, sizeof(ThostOrderAction.ParticipantID) - 1);
		ThostOrderAction.
		m_pSpi->OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	}
}
//查询投资者
void CFtdcTraderApiImpl::OnRspQryInvestor(CTORATstpInvestorField* pInvestor, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (m_pSpi)
	{
		CThostFtdcRspInfoField* pThostRspInfo = NULL;

		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}

		CThostFtdcInvestorField* pThostInvestor = NULL;
		CThostFtdcInvestorField  ThostInvestor;

		if (pInvestor)
		{
			memset(&ThostInvestor, 0x00, sizeof(ThostInvestor));
			strncpy(ThostInvestor.BrokerID, m_BrokerID, sizeof(ThostInvestor.BrokerID) - 1);
			strncpy(ThostInvestor.InvestorID, pInvestor->InvestorID, sizeof(ThostInvestor.InvestorID) - 1);
			strncpy(ThostInvestor.InvestorName, pInvestor->InvestorName, sizeof(ThostInvestor.InvestorName) - 1);
			strncpy(ThostInvestor.IdentifiedCardNo, pInvestor->IdCardNo, sizeof(ThostInvestor.IdentifiedCardNo)-1);
			strncpy(ThostInvestor.Mobile, pInvestor->Mobile, sizeof(ThostInvestor.Mobile) - 1);
			ThostInvestor.IsActive = 1;
			pThostInvestor = &ThostInvestor;
		}
		return m_pSpi->OnRspQryInvestor(pThostInvestor, pThostRspInfo, nRequestID, bIsLast);
	}
}


void CFtdcTraderApiImpl::OnRspQryInvestorTradingFee(CTORATstpInvestorTradingFeeField* pInvestorTradingFee, CTORATstpRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
	if (m_pSpi)
	{
		CThostFtdcRspInfoField* pThostRspInfo = NULL;

		if (pRspInfo)
		{
			memset(&ThostRspInfo, 0, sizeof(ThostRspInfo));
			ThostRspInfo.ErrorID = pRspInfo->ErrorID;
			strncpy(ThostRspInfo.ErrorMsg, pRspInfo->ErrorMsg, sizeof(ThostRspInfo.ErrorMsg) - 1);
			pThostRspInfo = &ThostRspInfo;
		}

		CThostFtdcInstrumentCommissionRateField* pThostInvestorFee = NULL;
		CThostFtdcInstrumentCommissionRateField  ThostInvestorFee = { 0 };

		if (pInvestorTradingFee)
		{
			strncpy(ThostInvestorFee.BrokerID, m_BrokerID, sizeof(ThostInvestorFee.BrokerID) - 1);
			strncpy(ThostInvestorFee.InvestorID, pInvestorTradingFee->InvestorID, sizeof(ThostInvestorFee.InvestorID) - 1);
			if (pInvestorTradingFee->ExchangeID == TORA_TSTP_EXD_SSE)
				strncpy(ThostInvestorFee.ExchangeID, EXCHANGE_SH, sizeof(ThostInvestorFee.ExchangeID) - 1);
			else if (pInvestorTradingFee->ExchangeID == TORA_TSTP_EXD_SZSE)
				strncpy(ThostInvestorFee.ExchangeID, EXCHANGE_SZ, sizeof(ThostInvestorFee.ExchangeID) - 1);
			else if (pInvestorTradingFee->ExchangeID == TORA_TSTP_EXD_BSE)
				strncpy(ThostInvestorFee.ExchangeID, EXCHANGE_BSE, sizeof(ThostInvestorFee.ExchangeID) - 1);
			else if (pInvestorTradingFee->ExchangeID == TORA_TSTP_EXD_HK)
				strncpy(ThostInvestorFee.ExchangeID, EXCHANGE_HKEX, sizeof(ThostInvestorFee.ExchangeID) - 1);
			
			if (strcmp(pInvestorTradingFee->SecurityID, "00000000") == 0)
				ThostInvestorFee.InstrumentID[0] = pInvestorTradingFee->ProductID;
			else if(strlen(pInvestorTradingFee->SecurityID))
				strncpy(ThostInvestorFee.InstrumentID, pInvestorTradingFee->SecurityID, sizeof(ThostInvestorFee.InstrumentID) - 1);
			
			ThostInvestorFee.OpenRatioByMoney = pInvestorTradingFee->RatioByAmt;
			ThostInvestorFee.OpenRatioByVolume = pInvestorTradingFee->FeeByVolume;
			ThostInvestorFee.CloseRatioByMoney = pInvestorTradingFee->RatioByAmt;
			ThostInvestorFee.CloseRatioByVolume = pInvestorTradingFee->FeeByVolume;
			ThostInvestorFee.CloseTodayRatioByMoney = pInvestorTradingFee->RatioByAmt;
			ThostInvestorFee.CloseTodayRatioByVolume = pInvestorTradingFee->FeeByVolume;
			pThostInvestorFee = &ThostInvestorFee;
		}
		return m_pSpi->OnRspQryInstrumentCommissionRate(pThostInvestorFee, pThostRspInfo, nRequestID, bIsLast);
	}
}
///报价查询请求
int CFtdcTraderApiImpl::ReqQryQuote(CThostFtdcQryQuoteField* pQryQuote, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryQuote, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///执行宣告查询请求
int CFtdcTraderApiImpl::ReqQryExecOrder(CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryExecOrder, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///期权自对冲查询请求
int CFtdcTraderApiImpl::ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryOptionSelfClose, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///期权自对冲录入请求
int CFtdcTraderApiImpl::ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspOptionSelfCloseInsert, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///期权自对冲操作请求
int CFtdcTraderApiImpl::ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspOptionSelfCloseAction, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///执行宣告录入请求
int CFtdcTraderApiImpl::ReqExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspExecOrderInsert, m_pSpi, pInputExecOrder, &ThostRspInfoNotSupported, nRequestID, true));
	return 0;
}

///执行宣告操作请求
int CFtdcTraderApiImpl::ReqExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspExecOrderAction, m_pSpi, pInputExecOrderAction, &ThostRspInfoNotSupported, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryCFMMCTradingAccountKey, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

int CFtdcTraderApiImpl::ReqQryParkedOrder(CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryParkedOrder, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询预埋撤单
int CFtdcTraderApiImpl::ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryParkedOrderAction, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询交易所保证金率
int CFtdcTraderApiImpl::ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryExchangeMarginRate, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询期权交易成本
int CFtdcTraderApiImpl::ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryOptionInstrTradeCost, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询期权合约手续费
int CFtdcTraderApiImpl::ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryOptionInstrCommRate, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询报单手续费
int CFtdcTraderApiImpl::ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryInstrumentOrderCommRate, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询交易编码
int CFtdcTraderApiImpl::ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryTradingCode, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询投资单元
int CFtdcTraderApiImpl::ReqQryInvestUnit(CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryInvestUnit, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询组合合约安全系数
int CFtdcTraderApiImpl::ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryCombInstrumentGuard, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询申请组合
int CFtdcTraderApiImpl::ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryCombAction, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询经纪公司交易算法
int CFtdcTraderApiImpl::ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryBrokerTradingAlgos, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求查询监控中心用户令牌
int CFtdcTraderApiImpl::ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQueryCFMMCTradingAccountToken, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///期货发起查询银行余额请求
int CFtdcTraderApiImpl::ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQueryBankAccountMoneyByFuture, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///查询用户当前支持的认证模式
int CFtdcTraderApiImpl::ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID)
{
	memset(&UserAuthMethodField, 0x00, sizeof(UserAuthMethodField));
	UserAuthMethodField.UsableAuthMethod = 0;

	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspUserAuthMethod, m_pSpi, &UserAuthMethodField, nullptr, nRequestID, true));
	return 0;
}

///请求查询二级代理商信息
int CFtdcTraderApiImpl::ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySecAgentTradeInfo, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

#ifdef V6_5_1
///查询最大报单数量请求
int CFtdcTraderApiImpl::ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID)
{
	m_io_service.post(boost::bind(&CFtdcTraderApiImpl::HandleReqQryMaxOrderVolume, this, *pQryMaxOrderVolume, nRequestID));
	return 0;
}
void CFtdcTraderApiImpl::HandleReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField& QryMaxOrderVolume, int nRequestID)
{
	CThostFtdcQryMaxOrderVolumeField MaxOrderVolume = { 0 };
	strncpy(MaxOrderVolume.BrokerID, QryMaxOrderVolume.BrokerID, sizeof(MaxOrderVolume.BrokerID) - 1);
	strncpy(MaxOrderVolume.InvestorID, QryMaxOrderVolume.InvestorID, sizeof(MaxOrderVolume.InvestorID) - 1);
	strncpy(MaxOrderVolume.ExchangeID, QryMaxOrderVolume.ExchangeID, sizeof(MaxOrderVolume.ExchangeID) - 1);
	strncpy(MaxOrderVolume.InstrumentID, QryMaxOrderVolume.InstrumentID, sizeof(MaxOrderVolume.InstrumentID) - 1);
	MaxOrderVolume.Direction = QryMaxOrderVolume.Direction;
	MaxOrderVolume.HedgeFlag = QryMaxOrderVolume.HedgeFlag;
	MaxOrderVolume.OffsetFlag = QryMaxOrderVolume.OffsetFlag;
	MaxOrderVolume.MaxVolume = INT32_MAX;
	strncpy(MaxOrderVolume.InvestUnitID, QryMaxOrderVolume.InvestUnitID, sizeof(MaxOrderVolume.InvestUnitID) - 1);

	if (m_pSpi) {
		m_pSpi->OnRspQryMaxOrderVolume(&MaxOrderVolume, nullptr, nRequestID, true);
	}
}

///请求查询分类合约
int CFtdcTraderApiImpl::ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryClassifiedInstrument, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///请求组合优惠比例
int CFtdcTraderApiImpl::ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryCombPromotionParam, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

#endif


#ifdef V6_6_1_P1

///投资者风险结算持仓查询
int CFtdcTraderApiImpl::ReqQryRiskSettleInvstPosition(CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryRiskSettleInvstPosition, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///风险结算产品查询
int CFtdcTraderApiImpl::ReqQryRiskSettleProductStatus(CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryRiskSettleProductStatus, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

#endif

#if defined(V6_6_7) || defined(V6_6_5_P1)

int CFtdcTraderApiImpl::ReqQryTraderOffer(CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryTraderOffer, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}
#endif

#if defined(V6_6_9)
///SPBM期货合约参数查询
int CFtdcTraderApiImpl::ReqQrySPBMFutureParameter(CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySPBMFutureParameter, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///SPBM期权合约参数查询
int CFtdcTraderApiImpl::ReqQrySPBMOptionParameter(CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySPBMOptionParameter, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///SPBM品种内对锁仓折扣参数查询
int CFtdcTraderApiImpl::ReqQrySPBMIntraParameter(CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySPBMIntraParameter, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///SPBM跨品种抵扣参数查询
int CFtdcTraderApiImpl::ReqQrySPBMInterParameter(CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySPBMInterParameter, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///SPBM组合保证金套餐查询
int CFtdcTraderApiImpl::ReqQrySPBMPortfDefinition(CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySPBMPortfDefinition, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///投资者SPBM套餐选择查询
int CFtdcTraderApiImpl::ReqQrySPBMInvestorPortfDef(CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQrySPBMInvestorPortfDef, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///投资者新型组合保证金系数查询
int CFtdcTraderApiImpl::ReqQryInvestorPortfMarginRatio(CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryInvestorPortfMarginRatio, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}

///投资者产品SPBM明细查询
int CFtdcTraderApiImpl::ReqQryInvestorProdSPBMDetail(CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID)
{
	m_io_service.post(boost::bind(&CThostFtdcTraderSpi::OnRspQryInvestorProdSPBMDetail, m_pSpi, nullptr, nullptr, nRequestID, true));
	return 0;
}
#endif
