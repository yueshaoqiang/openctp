#if !defined(_FTDCMDAPIIMPL_H)
#define _FTDCMDAPIIMPL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UTApi.h"
#include "ThostFtdcMdApi.h"

using namespace TORALEV1API;

///API�ӿ�ʵ��
class CFtdcMdApiImpl : public CThostFtdcMdApi, public CUTApi
{
public:	
	///���캯��
	CFtdcMdApiImpl();

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

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	virtual void RegisterSpi(CThostFtdcMdSpi *pSpi);

	///�û���¼����
	virtual int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLogin, int nRequestID);

	///�û��˳�����
	virtual int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID);

	///�������顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubscribeMarketData(char* ppInstrumentID[], int nCount);

	///�˶����顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeMarketData(char* ppInstrumentID[], int nCount);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///��ʱ��ʵ�ֵĽӿ�

	///ע�����ַ������û���Ϣ
	///@param pFensUserInfo���û���Ϣ��
	virtual void RegisterFensUserInfo(CThostFtdcFensUserInfoField * pFensUserInfo){return;};

	///����ѯ�ۡ�
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int SubscribeForQuoteRsp(char* ppInstrumentID[], int nCount) { return -3; }

	///�˶�ѯ�ۡ�
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	virtual int UnSubscribeForQuoteRsp(char* ppInstrumentID[], int nCount) { return -3; }

#if defined(V6_3_19) || defined(V6_5_1) || defined(V6_6_1_P1) || defined(V6_6_7) || defined(V6_6_9)
	///�����ѯ�鲥��Լ
	virtual int ReqQryMulticastInstrument(CThostFtdcQryMulticastInstrumentField *pQryMulticastInstrument, int nRequestID) { return -3; }
#endif

private:
	//���ӽ���֪ͨ
	/* ˵����
		1. ������Ϊϵͳ���ӣ�����û���κ��û���¼����������Ȼ��ά������״̬
	*/
	virtual void OnFrontConnected();

	//���ӶϿ�֪ͨ���û����账��API���Զ�����
	/* ˵����
		1. ���ӶϿ��������ڴ������ϵ�¼���û�����������״̬���������Ӻ����Ҫ���·��͵�¼����
	*/
	virtual void OnFrontDisconnected(int nReason);

	/*��¼Ӧ��*/
	virtual void OnRspUserLogin(CTORATstpRspUserLoginField* pRspUserLoginField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	/*�ǳ�Ӧ��*/
	virtual void OnRspUserLogout(CTORATstpUserLogoutField* pUserLogoutField, CTORATstpRspInfoField* pRspInfoField, int nRequestID);

	/*���鶩��Ӧ��*/
	virtual void OnRspSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo);

	/*�����˶�Ӧ��*/
	virtual void OnRspUnSubMarketData(CTORATstpSpecificSecurityField* pSpecificSecurity, CTORATstpRspInfoField* pRspInfo);

	/*����֪ͨ*/
	virtual void OnRtnMarketData(CTORATstpMarketDataField* pDepthMarketData);

	///������Ȩ����Ӧ��
	virtual void OnRspSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///�˶���Ȩ����Ӧ��
	virtual void OnRspUnSubSPMarketData(CTORATstpSpecificSecurityField* pSpecificSecurityField, CTORATstpRspInfoField* pRspInfoField);

	///��Ȩ����֪ͨ
	virtual void OnRtnSPMarketData(CTORATstpMarketDataField* pMarketDataField);
public:
	CTORATstpXMdApi*m_pUserApi;
	CThostFtdcMdSpi *m_pSpi;
	TThostFtdcDateType TradingDay;
};


#endif
