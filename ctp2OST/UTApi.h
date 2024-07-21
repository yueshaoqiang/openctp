
#pragma once

#include "UTApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#define UT_API_EXPORT __declspec(dllexport)
#else
#define UT_API_EXPORT 
#endif

class CUTSpi
{
public:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected(){};
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason){};
		
	//�����̨��֧�ֵĹ���ʱ����
	virtual void OnRspError(CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast){};
	

	///����
	virtual void OnRtnOrder(CUTOrderField *pOrder) {};

	///�ɽ�
	virtual void OnRtnTrade(CUTTradeField *pTrade) {};

	///���������ر�
	virtual void OnErrRtnOrderAction(CUTOrderActionField *pOrderAction) {};
	

	///��������ر�
	virtual void OnRspOrderInsert(CUTInputOrderField *pInputOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///���������ر�
	virtual void OnRspOrderAction(CUTInputOrderActionField *pInputOrderAction, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�û�����Ӧ��
	virtual void OnRspLogin(CUTRspLoginField *pRspLogin, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����޸�Ӧ��
	virtual void OnRspUserPasswordUpdate(CUTUserPasswordUpdateField *pUserPasswordUpdate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///ת�˴���ر�
	virtual void OnRspTransferInsert(CUTInputTransferField *pInputTransfer, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///ת��
	virtual void OnRtnTransfer(CUTTransferField *pTransfer) {};

	///ֱ�ӻ������ر�
	virtual void OnRspFundPaybackInsert(CUTInputFundPaybackField *pInputFundPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///ֱ�ӻ���
	virtual void OnRtnFundPayback(CUTFundPaybackField *pFundPayback) {};

	///ֱ�ӻ�ȯ����ر�
	virtual void OnRspStockPaybackInsert(CUTInputStockPaybackField *pInputStockPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///ֱ�ӻ�ȯ
	virtual void OnRtnStockPayback(CUTStockPaybackField *pStockPayback) {};

	///ͬ��������ص�ȯԴ���׶����Ϣ
	virtual void OnRtnPrivateCreditStock(CUTPrivateCreditStockField *pPrivateCreditStock) {};

	///����
	virtual void OnRtnLock(CUTLockField *pLock) {};

	///��������ر�
	virtual void OnRspLockInsert(CUTInputLockField *pInputLock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///��Ȩ
	virtual void OnRtnExecOrder(CUTExecOrderField *pExecOrder) {};

	///��Ȩ����ر�
	virtual void OnRspExecOrderInsert(CUTInputExecOrderField *pInputExecOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///��Ȩ�����ر�
	virtual void OnRspExecOrderAction(CUTInputExecOrderActionField *pInputExecOrderAction, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///��Ȩ�����ر�
	virtual void OnErrRtnExecOrderAction(CUTExecOrderActionField *pExecOrderAction) {};
	

	///�����ѯ��Լ��Ӧ
	virtual void OnRspQryInstrument(CUTInstrumentField *pInstrument, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ������Ӧ
	virtual void OnRspQryDepthMarketData(CUTDepthMarketDataField *pDepthMarketData, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ�ֲ���Ӧ
	virtual void OnRspQryInvestorPosition(CUTInvestorPositionField *pInvestorPosition, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ�ʽ���Ӧ
	virtual void OnRspQryTradingAccount(CUTTradingAccountField *pTradingAccount, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ��Ȩ��Լÿ�ֱ�֤����Ӧ
	virtual void OnRspQryOptionInstrMarginByVolume(CUTOptionInstrMarginByVolumeField *pOptionInstrMarginByVolume, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ��Ȩ����������Ӧ
	virtual void OnRspQryOptionInstrCommRate(CUTOptionInstrCommRateField *pOptionInstrCommRate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ������Ӧ
	virtual void OnRspQryOrder(CUTOrderField *pOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ�ɽ���Ӧ
	virtual void OnRspQryTrade(CUTTradeField *pTrade, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ����������Ӧ
	virtual void OnRspQryInstrumentCommissionRate(CUTInstrumentCommissionRateField *pInstrumentCommissionRate, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯͶ������Ӧ
	virtual void OnRspQryInvestor(CUTInvestorField *pInvestor, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯת����Ӧ
	virtual void OnRspQryTransfer(CUTTransferField *pTransfer, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ���ױ���
	virtual void OnRspQryTradingCode(CUTTradingCodeField *pTradingCode, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///��ѯ����µ�����Ӧ
	virtual void OnRspQryMaxOrderVolume(CUTMaxOrderVolumeField *pMaxOrderVolume, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ���ú�Լ������Ӧ
	virtual void OnRspQryCreditInstrument(CUTCreditInstrumentField *pCreditInstrument, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯͶ����������Ϣ��Ӧ
	virtual void OnRspQryCreditInvestor(CUTCreditInvestorField *pCreditInvestor, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯͶ���߿���ȯ��Ӧ
	virtual void OnRspQryPrivateCreditStock(CUTPrivateCreditStockField *pPrivateCreditStock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ���жȲ�����Ӧ
	virtual void OnRspQryCreditConcentration(CUTCreditConcentrationField *pCreditConcentration, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯͶ����������ϸ��Ӧ
	virtual void OnRspQryCreditFundDetail(CUTCreditFundDetailField *pCreditFundDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯͶ������ȯ��ϸ��Ӧ
	virtual void OnRspQryCreditStockDetail(CUTCreditStockDetailField *pCreditStockDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯͶ����ֱ�ӻ�����Ӧ
	virtual void OnRspQryFundPayback(CUTFundPaybackField *pFundPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯͶ����ֱ�ӻ�ȯ��Ӧ
	virtual void OnRspQryStockPayback(CUTStockPaybackField *pStockPayback, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ�������ʶ����Ӧ
	virtual void OnRspQryPublicCreditFund(CUTPublicCreditFundField *pPublicCreditFund, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯETF��Ϣ��Ӧ
	virtual void OnRspQryETFInfo(CUTETFInfoField *pETFInfo, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯETF�ɷֹ���Ӧ
	virtual void OnRspQryETFComponent(CUTETFComponentField *pETFComponent, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ��֤����������ϸ��Ӧ
	virtual void OnRspQryCreditAvailableDetail(CUTCreditAvailableDetailField *pCreditAvailableDetail, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ������Ӧ
	virtual void OnRspQryLock(CUTLockField *pLock, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ��Ȩ��Ӧ
	virtual void OnRspQryExecOrder(CUTExecOrderField *pExecOrder, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ������λ��Ӧ
	virtual void OnRspQryLockPosition(CUTLockPositionField *pLockPosition, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ��Ȩ�޲���Ӧ
	virtual void OnRspQryOptPosiLimit(CUTOptPosiLimitField *pOptPosiLimit, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	

	///�����ѯ��Ȩ�޶���Ӧ
	virtual void OnRspQryOptAmountLimit(CUTOptAmountLimitField *pOptAmountLimit, CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
	
};

class UT_API_EXPORT CUTApi
{
public:
	///����UserApi
	///@param pszFlowPath ����������Ϣ�ļ���Ŀ¼��Ĭ��Ϊ��ǰĿ¼
	///nCPUID    �󶨵�CPU ID,Ĭ�ϲ���
	static CUTApi *CreateApi(const char *pszFlowPath = "", int nCPUID = 0);
	
	///��ȡapi�汾
	static const char *GetApiVersion();
	
	///����ʹ��apiʱ,��Ҫ���øú���ɾ��֮
	virtual void Release() = 0;
	
	///��ʼ��api,���øú�����ӿڿ�ʼ����
	virtual void Init() = 0;
	
	///�ȴ��ӿ��߳̽���
	virtual int Join() = 0;
	
	///�������ص�ַ
	///pszFrontAddressǰ�õ�ַ;��tcp://127.0.0.1:8888,˵������Э����tcp,ip��ַ��127.0.0.1���˿ں���8888
	virtual void RegisterFront(char *pszFrontAddress) = 0;
	
	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CUTSpi *pSpi) = 0;
	
	///����˽����,�籨���ر�,�ɽ��ر����ú��������κ�ʱ�����,���������򲻻��յ�˽����������
	///nResumeType ���ķ�ʽ; UT_TERT_RESTART��ͷ��ʼ��,UT_TERT_RESUME����,UT_TERT_QUICKֻ����¼�����
	virtual void SubscribePrivateTopic(UT_TE_RESUME_TYPE nResumeType) = 0;
	
	///���Ĺ�����,��ʱû���������͡��ú���Ҫ�ڵ�¼ǰ����,���������򲻻��յ�������������
	///nResumeType ���ķ�ʽ; UT_TERT_RESTART��ͷ��ʼ��,UT_TERT_RESUME����,UT_TERT_QUICKֻ����¼�����
	virtual void SubscribePublicTopic(UT_TE_RESUME_TYPE nResumeType) = 0;
	
	///�ύ�ն���Ϣ;��¼�����;����ת����������Ҫ����
	///pSubmitTerminalInfo �ն���Ϣ(��ʽ"#OSTPMA;IIP=XXX;...")
	virtual void SubmitTerminalInfo(CUTSubmitTerminalInfoField* pSubmitTerminalInfo) = 0;
	
	///��������
	virtual int ReqOrderInsert(CUTInputOrderField *pInputOrder, int nRequestID) = 0;
	///��������
	virtual int ReqOrderAction(CUTInputOrderActionField *pInputOrderAction, int nRequestID) = 0;
	///�û���������
	virtual int ReqLogin(CUTReqLoginField *pReqLogin, int nRequestID) = 0;
	///�ǳ�����
	virtual int ReqLogout(CUTReqLogoutField *pReqLogout, int nRequestID) = 0;
	///�����޸�����
	virtual int ReqUserPasswordUpdate(CUTUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;
	///ת�˲���
	virtual int ReqTransferInsert(CUTInputTransferField *pInputTransfer, int nRequestID) = 0;
	///ֱ�ӻ������
	virtual int ReqFundPaybackInsert(CUTInputFundPaybackField *pInputFundPayback, int nRequestID) = 0;
	///ֱ�ӻ�ȯ����
	virtual int ReqStockPaybackInsert(CUTInputStockPaybackField *pInputStockPayback, int nRequestID) = 0;
	///��������
	virtual int ReqLockInsert(CUTInputLockField *pInputLock, int nRequestID) = 0;
	///��Ȩ����
	virtual int ReqExecOrderInsert(CUTInputExecOrderField *pInputExecOrder, int nRequestID) = 0;
	///��Ȩ����
	virtual int ReqExecOrderAction(CUTInputExecOrderActionField *pInputExecOrderAction, int nRequestID) = 0;
	///������������
	virtual int ReqOrderInsert(CUTInputOrderField *pInputOrder, int nCount, int nRequestID) = 0;
	///������������
	virtual int ReqOrderAction(CUTInputOrderActionField *pInputOrderAction, int nCount, int nRequestID) = 0;
	///�����ѯ��Լ
	virtual int ReqQryInstrument(CUTQryInstrumentField *pQryInstrument, int nRequestID) = 0;
	///�����ѯ����
	virtual int ReqQryDepthMarketData(CUTQryDepthMarketDataField *pQryDepthMarketData, int nRequestID) = 0;
	///�����ѯ�ֲ�
	virtual int ReqQryInvestorPosition(CUTQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;
	///�����ѯ�ʽ�
	virtual int ReqQryTradingAccount(CUTQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;
	///�����ѯ����
	virtual int ReqQryOrder(CUTQryOrderField *pQryOrder, int nRequestID) = 0;
	///�����ѯ�ɽ�
	virtual int ReqQryTrade(CUTQryTradeField *pQryTrade, int nRequestID) = 0;
	///�����ѯ��Ȩ��Լÿ�ֱ�֤��
	virtual int ReqQryOptionInstrMarginByVolume(CUTQryOptionInstrMarginByVolumeField *pQryOptionInstrMarginByVolume, int nRequestID) = 0;
	///�����ѯ��Ȩ��������
	virtual int ReqQryOptionInstrCommRate(CUTQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID) = 0;
	///�����ѯ��������
	virtual int ReqQryInstrumentCommissionRate(CUTQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID) = 0;
	///�����ѯͶ����
	virtual int ReqQryInvestor(CUTQryInvestorField *pQryInvestor, int nRequestID) = 0;
	///�����ѯת��
	virtual int ReqQryTransfer(CUTQryTransferField *pQryTransfer, int nRequestID) = 0;
	///�����ѯ���ױ���
	virtual int ReqQryTradingCode(CUTQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;
	///�����ѯ����µ���
	virtual int ReqQryMaxOrderVolume(CUTQryMaxOrderVolumeField *pQryMaxOrderVolume, int nRequestID) = 0;
	///�����ѯ���ú�Լ����
	virtual int ReqQryCreditInstrument(CUTQryCreditInstrumentField *pQryCreditInstrument, int nRequestID) = 0;
	///�����ѯͶ����������Ϣ
	virtual int ReqQryCreditInvestor(CUTQryCreditInvestorField *pQryCreditInvestor, int nRequestID) = 0;
	///�����ѯͶ���߿���ȯ
	virtual int ReqQryPrivateCreditStock(CUTQryPrivateCreditStockField *pQryPrivateCreditStock, int nRequestID) = 0;
	///�����ѯ���жȲ���
	virtual int ReqQryCreditConcentration(CUTQryCreditConcentrationField *pQryCreditConcentration, int nRequestID) = 0;
	///�����ѯͶ����������ϸ
	virtual int ReqQryCreditFundDetail(CUTQryCreditFundDetailField *pQryCreditFundDetail, int nRequestID) = 0;
	///�����ѯͶ������ȯ��ϸ
	virtual int ReqQryCreditStockDetail(CUTQryCreditStockDetailField *pQryCreditStockDetail, int nRequestID) = 0;
	///�����ѯͶ����ֱ�ӻ���
	virtual int ReqQryFundPayback(CUTQryFundPaybackField *pQryFundPayback, int nRequestID) = 0;
	///�����ѯͶ����ֱ�ӻ�ȯ
	virtual int ReqQryStockPayback(CUTQryStockPaybackField *pQryStockPayback, int nRequestID) = 0;
	///�����ѯ�������ʶ��
	virtual int ReqQryPublicCreditFund(CUTQryPublicCreditFundField *pQryPublicCreditFund, int nRequestID) = 0;
	///�����ѯETF��Ϣ
	virtual int ReqQryETFInfo(CUTQryETFInfoField *pQryETFInfo, int nRequestID) = 0;
	///�����ѯETF�ɷֹ�
	virtual int ReqQryETFComponent(CUTQryETFComponentField *pQryETFComponent, int nRequestID) = 0;
	///�����ѯ��֤����������ϸ
	virtual int ReqQryCreditAvailableDetail(CUTQryCreditAvailableDetailField *pQryCreditAvailableDetail, int nRequestID) = 0;
	///�����ѯ����
	virtual int ReqQryLock(CUTQryLockField *pQryLock, int nRequestID) = 0;
	///�����ѯ��Ȩ
	virtual int ReqQryExecOrder(CUTQryExecOrderField *pQryExecOrder, int nRequestID) = 0;
	///�����ѯ������λ
	virtual int ReqQryLockPosition(CUTQryLockPositionField *pQryLockPosition, int nRequestID) = 0;
	///�����ѯ��Ȩ�޲�
	virtual int ReqQryOptPosiLimit(CUTQryOptPosiLimitField *pQryOptPosiLimit, int nRequestID) = 0;
	///�����ѯ��Ȩ�޶�
	virtual int ReqQryOptAmountLimit(CUTQryOptAmountLimitField *pQryOptAmountLimit, int nRequestID) = 0;


protected:
	~CUTApi(){};
};
