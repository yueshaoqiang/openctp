#if !defined(_FTDCTRADERAPIIMPL_H)
#define _FTDCTRADERAPIIMPL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UTApi.h"
#include "ThostFtdcTraderApi.h"
#include <thread>

///API�ӿ�ʵ��
class CFtdcTraderApiImpl : public CThostFtdcTraderApi, public CUTSpi
{
public:	
	///���캯��
	CFtdcTraderApiImpl(const char *pszFlowPath="");

	void OnTime(const boost::system::error_code& err);

	///��ȡAPI�İ汾��Ϣ
	///@retrun ��ȡ���İ汾��
	//const char *GetApiVersion(){return 0;};

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	virtual void Release();
	
	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	virtual void Init();
	
	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	virtual int Join();
	
	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	virtual const char *GetTradingDay();
	
	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	virtual void RegisterFront(char *pszFrontAddress);
	
	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterFront������RegisterNameServer
	virtual void RegisterNameServer(char *pszNsAddress);

	///ע�����ַ������û���Ϣ
	///@param pFensUserInfo���û���Ϣ��
	virtual void RegisterFensUserInfo(CThostFtdcFensUserInfoField * pFensUserInfo);

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CThostFtdcTraderSpi *pSpi);

	///����˽������
	///@param nResumeType ˽�����ش���ʽ  
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼��˽����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
	virtual void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType);
	
	///���Ĺ�������
	///@param nResumeType �������ش���ʽ  
	///        THOST_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        THOST_TERT_RESUME:���ϴ��յ�������
	///        THOST_TERT_QUICK:ֻ���͵�¼�󹫹���������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
	virtual void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType);

	///�û���¼����
	virtual int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLogin, int nRequestID);

	///�û��˳�����
	virtual int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID);
	///�û������޸�����
	virtual int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID);

	///����¼������
	virtual int ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID);

	///������������
	virtual int ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID);

	///������ѯ����
	virtual int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID);

	///�ɽ�����ѯ����
	virtual int ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID);

	///�����ѯ�ʽ��˻�
	virtual int ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID);

	///��Լ��ѯ����
	virtual int ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID);

	///��������ѯ����
	virtual int ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID);

	///Ͷ���ֲֲ߳�ѯ����
	virtual int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID);

	///�����ѯ��Լ��֤����
	virtual int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID);
	
	///�����ѯ��Լ��������
	virtual int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID);	

	///�����ѯͶ����
	virtual int ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID);

	///�����ѯ����
	virtual int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID);

	///�����ѯ��Ʒ
	virtual int ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID);
	virtual int HandleReqQryProduct(CThostFtdcQryProductField QryProduct, int nRequestID);

	
	///Ͷ���߽�����ȷ��
	virtual int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID);

	///�����ѯ���͹�˾���ײ���
	virtual int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID);

	///�����ѯͶ���ֲ߳���ϸ
	virtual int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID);

	///�����ѯͶ���ֲ߳���ϸ
	virtual int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID);

	///�����ѯ������Ϣȷ��
	virtual int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID);

	///�����ѯͶ���߽�����
	virtual int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID);

	///�����ѯ��Ʒ��
	virtual int ReqQryProductGroup(CThostFtdcQryProductGroupField *pQryProductGroup, int nRequestID);

	///�����ѯ����ǩԼ��ϵ
	virtual int ReqQryAccountregister(CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID);

	///�����ѯǩԼ����
	virtual int ReqQryContractBank(CThostFtdcQryContractBankField *pQryContractBank, int nRequestID);

	///�����ѯ����֪ͨ
	virtual int ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID);


	///�����ѯ�ͻ�֪ͨ
	virtual int ReqQryNotice(CThostFtdcQryNoticeField *pQryNotice, int nRequestID);
	
	///�ͻ�����֤����
	virtual int ReqAuthenticate(CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID);
	virtual void HandleReqAuthenticate(CThostFtdcReqAuthenticateField& AuthenticateField, int nRequestID);


	///�����ѯת����ˮ
	virtual int ReqQryTransferSerial(CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID);

	///�����ѯת������
	virtual int ReqQryTransferBank(CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID);

	///�����ѯѯ��
	virtual int ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID);
	

	///�ʽ��˻������������
	virtual int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID){return -3;};

	///Ԥ��¼������
	virtual int ReqParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, int nRequestID){return -3;};

	///Ԥ�񳷵�¼������
	virtual int ReqParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID){return -3;};

	///��ѯ��󱨵���������
#ifdef V6_5_1
	virtual int ReqQueryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID){return -3;};
#else
	virtual int ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID){return -3;};
#endif
	///����ɾ��Ԥ��
	virtual int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID){return -3;};

	///����ɾ��Ԥ�񳷵�
	virtual int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID){return -3;};

	///ִ������¼������
	virtual int ReqExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID);

	///ִ�������������
	virtual int ReqExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID);

	///ѯ��¼������
	virtual int ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID);

	///����¼������
	virtual int ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID);

	///���۲�������
	virtual int ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID);

	///����������������
	virtual int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID){return -3;};

	///��Ȩ�ԶԳ�¼������
	virtual int ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField *pInputOptionSelfClose, int nRequestID);

	///��Ȩ�ԶԳ��������
	virtual int ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField *pInputOptionSelfCloseAction, int nRequestID);

	///�������¼������
	virtual int ReqCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, int nRequestID){return -3;};

	///�����ѯ���ױ���
	virtual int ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID);

	///�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
	virtual int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID);

	///�����ѯ�ֵ��۵���Ϣ
	virtual int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID){return -3;};

	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
	virtual int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID){return -3;};

	///�����ѯ��������֤����
	virtual int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID);

	///�����ѯ������������֤����
	virtual int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID){return -3;};

	///�����ѯ����
	virtual int ReqQryExchangeRate(CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID){return -3;};

	///�����ѯ�����������Ա����Ȩ��
	virtual int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID){return -3;};

	///�����ѯ��Ʒ���ۻ���
	virtual int ReqQryProductExchRate(CThostFtdcQryProductExchRateField *pQryProductExchRate, int nRequestID){return -3;};

	///�����ѯ�����̺�Լ��������
	virtual int ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField *pQryMMInstrumentCommissionRate, int nRequestID) {return -3; };

	///�����ѯ��������Ȩ��Լ������
	virtual int ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField *pQryMMOptionInstrCommRate, int nRequestID) {return -3; };

	///�����ѯ����������
	virtual int ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID);

	///�����ѯ�ʽ��˻�
	virtual int ReqQrySecAgentTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID) {return -3; };

	///�����ѯ�����������ʽ�У��ģʽ
	virtual int ReqQrySecAgentCheckMode(CThostFtdcQrySecAgentCheckModeField *pQrySecAgentCheckMode, int nRequestID) {return -3; };

	///�����ѯ��Ȩ���׳ɱ�
	virtual int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID);

	///�����ѯ��Ȩ��Լ������
	virtual int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID);

	///�����ѯִ������
	virtual int ReqQryExecOrder(CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID);

	///�����ѯ����
	virtual int ReqQryQuote(CThostFtdcQryQuoteField* pQryQuote, int nRequestID);

	///�����ѯ��Ȩ�ԶԳ�
	virtual int ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID);

	///�����ѯͶ�ʵ�Ԫ
	virtual int ReqQryInvestUnit(CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID);

	///�����ѯ��Ϻ�Լ��ȫϵ��
	virtual int ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID);

	///�����ѯ�������
	virtual int ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID);

	///�����ѯԤ��
	virtual int ReqQryParkedOrder(CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID);

	///�����ѯԤ�񳷵�
	virtual int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID);

	///�����ѯ���͹�˾�����㷨
	virtual int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID);

	///�����ѯ��������û�����
	virtual int ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID);

	///�ڻ����������ʽ�ת�ڻ�����
	virtual int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID){return -3;};

	///�ڻ������ڻ��ʽ�ת��������
	virtual int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID){return -3;};

	///�ڻ������ѯ�����������
	virtual int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID);

	///ע���û��ն���Ϣ�������м̷�����������ģʽ
	///��Ҫ���ն���֤�ɹ����û���¼ǰ���øýӿ�
	virtual int RegisterUserSystemInfo(CThostFtdcUserSystemInfoField *pUserSystemInfo) {return -3;};

	///�ϱ��û��ն���Ϣ�������м̷���������Ա��¼ģʽ
	///����Ա��¼�󣬿��Զ�ε��øýӿ��ϱ��ͻ���Ϣ
	virtual int SubmitUserSystemInfo(CThostFtdcUserSystemInfoField *pUserSystemInfo) {return -3;};

	///��ѯ�û���ǰ֧�ֵ���֤ģʽ
	virtual int ReqUserAuthMethod(CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID);

	///�û�������ȡͼ����֤������
	virtual int ReqGenUserCaptcha(CThostFtdcReqGenUserCaptchaField *pReqGenUserCaptcha, int nRequestID) {return -3;};

	///�û�������ȡ������֤������
	virtual int ReqGenUserText(CThostFtdcReqGenUserTextField *pReqGenUserText, int nRequestID) {return -3;};

	///�û���������ͼƬ��֤��ĵ�½����
	virtual int ReqUserLoginWithCaptcha(CThostFtdcReqUserLoginWithCaptchaField *pReqUserLoginWithCaptcha, int nRequestID) {return -3;};

	///�û��������ж�����֤��ĵ�½����
	virtual int ReqUserLoginWithText(CThostFtdcReqUserLoginWithTextField *pReqUserLoginWithText, int nRequestID) {return -3;};

	///�û��������ж�̬����ĵ�½����
	virtual int ReqUserLoginWithOTP(CThostFtdcReqUserLoginWithOTPField *pReqUserLoginWithOTP, int nRequestID) {return -3;};

	///�����ѯ������������Ϣ
	virtual int ReqQrySecAgentTradeInfo(CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID);

#ifdef V6_5_1
	///��ѯ��󱨵���������
	virtual int ReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID);
	void HandleReqQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField& QryMaxOrderVolume, int nRequestID);

	///�����ѯ�����Լ
	virtual int ReqQryClassifiedInstrument(CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID);

	///��������Żݱ���
	virtual int ReqQryCombPromotionParam(CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID);
#endif

#ifdef V6_6_1_P1
	///Ͷ���߷��ս���ֲֲ�ѯ
	virtual int ReqQryRiskSettleInvstPosition(CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID);

	///���ս����Ʒ��ѯ
	virtual int ReqQryRiskSettleProductStatus(CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID);
#endif

#if defined(V6_6_7) || defined(V6_6_5_P1)
	///�����ѯ����Ա���̻�
	virtual int ReqQryTraderOffer(CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID);
#endif

#ifdef V6_6_9
	///SPBM�ڻ���Լ������ѯ
	virtual int ReqQrySPBMFutureParameter(CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID);

	///SPBM��Ȩ��Լ������ѯ
	virtual int ReqQrySPBMOptionParameter(CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID);

	///SPBMƷ���ڶ������ۿ۲�����ѯ
	virtual int ReqQrySPBMIntraParameter(CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID);

	///SPBM��Ʒ�ֵֿ۲�����ѯ
	virtual int ReqQrySPBMInterParameter(CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID);

	///SPBM��ϱ�֤���ײͲ�ѯ
	virtual int ReqQrySPBMPortfDefinition(CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID);

	///Ͷ����SPBM�ײ�ѡ���ѯ
	virtual int ReqQrySPBMInvestorPortfDef(CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID);

	///Ͷ����������ϱ�֤��ϵ����ѯ
	virtual int ReqQryInvestorPortfMarginRatio(CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID);

	///Ͷ���߲�ƷSPBM��ϸ��ѯ
	virtual int ReqQryInvestorProdSPBMDetail(CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID);
#endif

private:
	///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
	virtual void OnFrontConnected();
	
	///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
	///@param nReason ����ԭ��
	///        0x1001 �����ʧ��
	///        0x1002 ����дʧ��
	///        0x2001 ����������ʱ
	///        0x2002 ��������ʧ��
	///        0x2003 �յ�������
	virtual void OnFrontDisconnected(int nReason);
		
	//�����̨��֧�ֵĹ���ʱ����
	virtual void OnRspError(CUTRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	

	///����
	virtual void OnRtnOrder(CUTOrderField *pOrder);

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

private:
	TThostFtdcInvestorIDType m_InvestorID;
	TThostFtdcUserIDType m_UserID;
	TThostFtdcBrokerIDType m_BrokerID;
	TThostFtdcFrontIDType m_FrontID;
	TThostFtdcSessionIDType m_SessionID;
	CThostFtdcRspUserLoginField  ThostRspUserLogin;

	// ģ����Ӧ
	CThostFtdcRspInfoField  ThostRspInfo;
	CThostFtdcRspInfoField  ThostRspInfoNotSupported;
	CThostFtdcRspAuthenticateField RspAuthenticateField;
	CThostFtdcSettlementInfoConfirmField SettlementInfoConfirmField;
	CThostFtdcBrokerTradingParamsField BrokerTradingParamsField;
	CThostFtdcInvestorField  ThostRspInvestor;
	CThostFtdcSettlementInfoConfirmField ThostSettlementInfoConfirmField;
	CThostFtdcRspUserAuthMethodField UserAuthMethodField;

	TThostFtdcDateType	TradingDay;

public:
	CUTApi *m_pUserApi;
	CThostFtdcTraderSpi *m_pSpi;
};


#endif
