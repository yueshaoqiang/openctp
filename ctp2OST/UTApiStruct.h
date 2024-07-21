#pragma once

#include "UTApiDataType.h"


///��Ȩ��Լ��֤����
struct CUTOptionInstrMarginRateField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TUTInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///��֤�����ϵ��
	TUTRatioType	MarginRatioByMoney;
	///��֤�����ϵ��
	TUTMoneyType	MarginRatioByVolume;
};
///��������
struct CUTInstrumentCommissionRateField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TUTInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�ֲַ���
	TUTPosiDirectionType	PosiDirection;
	///������������
	TUTRatioType	OpenRatioByMoney;
	///����������
	TUTRatioType	OpenRatioByVolume;
	///ƽ����������
	TUTRatioType	CloseRatioByMoney;
	///ƽ��������
	TUTRatioType	CloseRatioByVolume;
	///ƽ����������
	TUTRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TUTRatioType	CloseTodayRatioByVolume;
	///����˰��
	TUTRatioType	OpenTaxRatioByMoney;
	///����˰��
	TUTRatioType	OpenTaxRatioByVolume;
	///ƽ��˰��
	TUTRatioType	CloseTaxRatioByMoney;
	///ƽ��˰��
	TUTRatioType	CloseTaxRatioByVolume;
	///�����Ѱ�����
	TUTMoneyType	CommByOrder;
	///ÿ�ʱ������������(������CommByOrder)
	TUTMoneyType	MinCommByOrder;
};
///�ʽ�
struct CUTTradingAccountField
{
	///Ͷ�����ʺ�
	TUTAccountIDType	AccountID;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///�˻�����
	TUTAccTypeType	AccType;
	///������
	TUTDateType	TradingDay;
	///�ϴ���Ѻ���
	TUTMoneyType	PreMortgage;
	///�ϴ����ö��
	TUTMoneyType	PreCredit;
	///�ϴδ���
	TUTMoneyType	PreDeposit;
	///�ϴν���׼����
	TUTMoneyType	PreBalance;
	///�ϴ�ռ�õı�֤��
	TUTMoneyType	PreMargin;
	///��Ϣ����
	TUTMoneyType	InterestBase;
	///��Ϣ����
	TUTMoneyType	Interest;
	///�����
	TUTMoneyType	Deposit;
	///������
	TUTMoneyType	Withdraw;
	///����ı�֤��
	TUTMoneyType	FrozenMargin;
	///������ʽ�
	TUTMoneyType	FrozenCash;
	///�����������
	TUTMoneyType	FrozenCommission;
	///��ǰ��֤���ܶ�
	TUTMoneyType	CurrMargin;
	///�ʽ���
	TUTMoneyType	CashIn;
	///������
	TUTMoneyType	Commission;
	///ƽ��ӯ��
	TUTMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TUTMoneyType	PositionProfit;
	///�ڻ�����׼����
	TUTMoneyType	Balance;
	///�����ʽ�
	TUTMoneyType	Available;
	///��ȡ�ʽ�
	TUTMoneyType	WithdrawQuota;
	///����׼����
	TUTMoneyType	Reserve;
	///���ö��
	TUTMoneyType	Credit;
	///��Ѻ���
	TUTMoneyType	Mortgage;
	///Ͷ���߽��֤��
	TUTMoneyType	DeliveryMargin;
	///˰��
	TUTMoneyType	Tax;
	///���ʽ��
	TUTMoneyType	CreditFund;
	///��������ʽ��
	TUTMoneyType	CreditFundFrozen;
	///��ȯ���
	TUTMoneyType	CreditStock;
	///�������ȯ���
	TUTMoneyType	CreditStockFrozen;
	///��֤��������
	TUTMoneyType	CreditAvailable;
	///��֤��������
	TUTMoneyType	CreditAvailableParam;
	///��ȯƽ�ֶ���(���㱣֤��������ͷǸ���ͨ���ֿ���)
	TUTMoneyType	CreditStockCloseFrozen;
	///����Ʒ���붳��ƫ��(���㱣֤��������)
	TUTMoneyType	CreditCollBuyFrozenOffset;
	///����֤ͨȯ���ֳɱ�
	TUTMoneyType	CreditLiquidCost;
	///������ȯ��Ϣ(���㱣֤��������ͻ���)
	TUTMoneyType	CreditInterest;
	///֤ȯ��ֵ
	TUTMoneyType	CreditTotalValue;
	///��ȯ��ǰ��ֵ
	TUTMoneyType	CreditStockValue;
	///�����ѻ����ʽ��(������Ϣ)
	TUTMoneyType	CreditFundPayback;
	///������ȯδ����Ϣ(���ɻ�)
	TUTMoneyType	CreditInterestProcess;
	///��������������(���ɻ�)
	TUTMoneyType	CreditFundCommission;
};
///�ֲ�
struct CUTInvestorPositionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TUTPosiDirectionType	PosiDirection;
	///���ճֲ�
	TUTLargeVolumeType	YdPosition;
	///�ֲܳ�
	TUTLargeVolumeType	Position;
	///��ͷ����
	TUTLargeVolumeType	LongFrozen;
	///��ͷ����
	TUTLargeVolumeType	ShortFrozen;
	///��ͷ������
	TUTMoneyType	LongFrozenAmount;
	///��ͷ������
	TUTMoneyType	ShortFrozenAmount;
	///������
	TUTLargeVolumeType	OpenVolume;
	///ƽ����
	TUTLargeVolumeType	CloseVolume;
	///���ֽ��
	TUTMoneyType	OpenAmount;
	///ƽ�ֽ��
	TUTMoneyType	CloseAmount;
	///�ֲֳɱ�
	TUTMoneyType	PositionCost;
	///ռ�õı�֤��
	TUTMoneyType	UseMargin;
	///����ı�֤��
	TUTMoneyType	FrozenMargin;
	///������ʽ�
	TUTMoneyType	FrozenCash;
	///�����������
	TUTMoneyType	FrozenCommission;
	///�ʽ���
	TUTMoneyType	CashIn;
	///������
	TUTMoneyType	Commission;
	///ƽ��ӯ��
	TUTMoneyType	CloseProfit;
	///�ֲ�ӯ��
	TUTMoneyType	PositionProfit;
	///�ϴν����
	TUTPriceType	PreSettlementPrice;
	///���ν����
	TUTPriceType	SettlementPrice;
	///������
	TUTDateType	TradingDay;
	///���ֳɱ�
	TUTMoneyType	OpenCost;
	///��ϳɽ��γɵĳֲ�
	TUTLargeVolumeType	CombPosition;
	///���ն���ƽ��ӯ��
	TUTMoneyType	CloseProfitByDate;
	///��ʶԳ�ƽ��ӯ��
	TUTMoneyType	CloseProfitByTrade;
	///���ճֲ�
	TUTLargeVolumeType	TodayPosition;
	///ÿ�ֱ�֤��
	TUTRatioType	MarginByVolume;
	///ִ�ж���
	TUTLargeVolumeType	StrikeFrozen;
	///ִ�ж�����
	TUTMoneyType	StrikeFrozenAmount;
	///����ִ�ж���
	TUTLargeVolumeType	AbandonFrozen;
	///���ʽ��
	TUTMoneyType	CreditFund;
	///ETF����ֲ�(�����ֲܳ�)
	TUTLargeVolumeType	RedemptionPosition;
	///�����ֱ�ӻ�ȯ��ɵĶ���
	TUTLargeVolumeType	RedemptionFrozen;
	///������ɵ�ETF����ֲֶ���
	TUTLargeVolumeType	RedemptionPositionFrozen;
	///��������
	TUTMoneyType	CreditFundVolume;
	///���ʽ��������(���ɻ�)
	TUTMoneyType	CreditFundCommission;
};
///����
struct CUTDepthMarketDataField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///������
	TUTDateType	TradingDay;
	///�ϴν����;����Ϊ��һ�վ�ֵ
	TUTPriceType	PreSettlementPrice;
	///������
	TUTPriceType	PreClosePrice;
	///��ֲ���
	TUTLargeVolumeType	PreOpenInterest;
	///��ͣ���
	TUTPriceType	UpperLimitPrice;
	///��ͣ���
	TUTPriceType	LowerLimitPrice;
	///��Ȼ��
	TUTDateType	ActionDay;
	///����޸�ʱ��
	TUTTimeType	UpdateTime;
	///����
	TUTPriceType	OpenPrice;
	///������
	TUTPriceType	ClosePrice;
	///���ν����;����Ϊʵʱ�ο���ֵ
	TUTPriceType	SettlementPrice;
	///��߼�
	TUTPriceType	HighestPrice;
	///��ͼ�
	TUTPriceType	LowestPrice;
	///��Լ����״̬
	TUTInstrumentStatusType	InstrumentStatus;
	///���¼�
	TUTPriceType	LastPrice;
	///����
	TUTLargeVolumeType	Volume;
	///�ɽ����
	TUTMoneyType	Turnover;
	///�ֲ���
	TUTLargeVolumeType	OpenInterest;
	///�����һ
	TUTPriceType	BidPrice1;
	///������һ
	TUTPriceType	AskPrice1;
	///������һ
	TUTLargeVolumeType	BidVolume1;
	///������һ
	TUTLargeVolumeType	AskVolume1;
	///����۶�
	TUTPriceType	BidPrice2;
	///�����۶�
	TUTPriceType	AskPrice2;
	///��������
	TUTLargeVolumeType	BidVolume2;
	///��������
	TUTLargeVolumeType	AskVolume2;
	///�������
	TUTPriceType	BidPrice3;
	///��������
	TUTPriceType	AskPrice3;
	///��������
	TUTLargeVolumeType	BidVolume3;
	///��������
	TUTLargeVolumeType	AskVolume3;
	///�������
	TUTPriceType	BidPrice4;
	///��������
	TUTPriceType	AskPrice4;
	///��������
	TUTLargeVolumeType	BidVolume4;
	///��������
	TUTLargeVolumeType	AskVolume4;
	///�������
	TUTPriceType	BidPrice5;
	///��������
	TUTPriceType	AskPrice5;
	///��������
	TUTLargeVolumeType	BidVolume5;
	///��������
	TUTLargeVolumeType	AskVolume5;
};
///��Լ
struct CUTInstrumentField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��Լ����
	TUTInstrumentNameType	InstrumentName;
	///��Ʒ����
	TUTProductIDType	ProductID;
	///��Ʒ����
	TUTProductClassType	ProductClass;
	///�������
	TUTYearType	DeliveryYear;
	///������
	TUTMonthType	DeliveryMonth;
	///�м۵�����µ���
	TUTVolumeType	MaxMarketOrderVolume;
	///�м۵���С�µ���
	TUTVolumeType	MinMarketOrderVolume;
	///�޼۵�����µ���
	TUTVolumeType	MaxLimitOrderVolume;
	///�޼۵���С�µ���
	TUTVolumeType	MinLimitOrderVolume;
	///��Լ��������
	TUTVolumeMultipleType	VolumeMultiple;
	///��С�䶯��λ
	TUTPriceType	PriceTick;
	///������
	TUTDateType	CreateDate;
	///������
	TUTDateType	OpenDate;
	///������
	TUTDateType	ExpireDate;
	///��ʼ������
	TUTDateType	StartDelivDate;
	///����������
	TUTDateType	EndDelivDate;
	///��ǰ�Ƿ���
	TUTBoolType	IsTrading;
	///��Լ��������״̬
	TUTInstLifePhaseType	InstLifePhase;
	///�ֲ�����
	TUTPositionTypeType	PositionType;
	///�ֲ���������
	TUTPositionDateTypeType	PositionDateType;
	///�Ƿ�ʹ�ô��߱�֤���㷨
	TUTMaxMarginSideAlgorithmType	MaxMarginSideAlgorithm;
	///��Ȩ����
	TUTOptionsTypeType	OptionsType;
	///�������
	TUTCombinationTypeType	CombinationType;
	///������Ʒ����;֤ȯʱ��ʾ�����,��Ȩʱ��ʾ���
	TUTInstrumentIDType	UnderlyingInstrID;
	///ִ�м�
	TUTPriceType	StrikePrice;
	///��Լ������Ʒ����;������Ȩ��ʾ������ÿ�ֱ�֤��
	TUTUnderlyingMultipleType	UnderlyingMultiple;
	///�޼۵���С���µ���λ
	TUTVolumeType	MinBuyVolume;
	///�޼۵���С���µ���λ
	TUTVolumeType	MinSellVolume;
	///��Լ��ʶ��;֤ȯʱ�ڲ�ʹ��,������Ȩʱ��ʾ��ԼӢ����
	TUTInstrumentCodeType	InstrumentCode;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///�м۵���С���µ���λ;������Ȩ��ʾ����1�Ŵ�1000��
	TUTVolumeType	MinMarketBuyVolume;
	///�м۵���С���µ���λ;������Ȩ��ʾ����2�Ŵ�1000��
	TUTVolumeType	MinMarketSellVolume;
};
///Ͷ����
struct CUTInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///Ͷ���߷������
	TUTInvestorIDType	InvestorGroupID;
	///Ͷ��������
	TUTPartyNameType	InvestorName;
	///֤������
	TUTIdCardTypeType	IdentifiedCardType;
	///֤������
	TUTIdentifiedCardNoType	IdentifiedCardNo;
	///�Ƿ��Ծ
	TUTBoolType	IsActive;
	///��ϵ�绰
	TUTTelephoneType	Telephone;
	///ͨѶ��ַ
	TUTAddressType	Address;
	///��������
	TUTDateType	OpenDate;
	///�ֻ�
	TUTMobileType	Mobile;
	///��������ģ�����
	TUTInvestorIDType	CommModelID;
	///��֤����ģ�����
	TUTInvestorIDType	MarginModelID;
	///��֯�ܹ�����
	TUTInvestorIDType	DepartmentID;
	///Ͷ�����ն���֤�������
	TUTInvestorIDType	AuthGroupID;
	///Ͷ���ߺ�Լ����Ȩ�޷������
	TUTInvestorIDType	TradingRightGroupID;
	///Ͷ���߰�װ���
	TUTInstallIDType	InvestorInstallID;
};
///��Ȩ��������
struct CUTOptionInstrCommRateField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TUTInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�ֲַ���
	TUTPosiDirectionType	PosiDirection;
	///������������
	TUTRatioType	OpenRatioByMoney;
	///����������
	TUTRatioType	OpenRatioByVolume;
	///ƽ����������
	TUTRatioType	CloseRatioByMoney;
	///ƽ��������
	TUTRatioType	CloseRatioByVolume;
	///ƽ����������
	TUTRatioType	CloseTodayRatioByMoney;
	///ƽ��������
	TUTRatioType	CloseTodayRatioByVolume;
	///ִ����������
	TUTRatioType	StrikeRatioByMoney;
	///ִ��������
	TUTRatioType	StrikeRatioByVolume;
	///Ӷ�𰴱���
	TUTMoneyType	CommByOrder;
};
///������
struct CUTExchangeField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������
	TUTExchangeNameType	ExchangeName;
};
///���͹�˾�û�����
struct CUTBrokerUserPasswordField
{
	///�û�����
	TUTUserIDType	UserID;
	///����
	TUTPasswordType	Password;
	///�û�����
	TUTUserNameType	UserName;
	///�û�����
	TUTUserTypeType	UserType;
	///�Ƿ��Ծ
	TUTBoolType	IsActive;
};
///����������Ա��Ϣ
struct CUTTraderField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Ա����
	TUTParticipantIDType	ParticipantID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///����Ա����
	TUTTraderClassType	TraderClass;
	///ҵ������
	TUTBizTypeType	BizType;
	///����
	TUTPasswordType	Password;
	///��װ���
	TUTInstallIDType	InstallID;
	///���ر������
	TUTOrderLocalIDType	OrderLocalID;
	///������������
	TUTDateType	TradingDay;
	///�������������ĺ�
	TUTDataCenterIDType	DataCenterID;
	///����������Ա����״̬
	TUTTraderConnectStatusType	TraderConnectStatus;
};
///����Ա��֯�ܹ���ϵ
struct CUTDepartmentUserField
{
	///�û�����
	TUTUserIDType	UserID;
	///Ͷ���߷�Χ
	TUTDepartmentRangeType	InvestorRange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///���ױ���
struct CUTTradingCodeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///�Ƿ��Ծ
	TUTBoolType	IsActive;
	///���ױ�������
	TUTClientIDTypeType	ClientIDType;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///Ӫҵ��ǰ׺���
	TUTBranchIDType	PreBranchID;
	///����Ӫҵ��
	TUTBranchIDType	DepartmentBranchID;
};
///��Ա����;��͹�˾������ձ�
struct CUTPartBrokerField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Ա����
	TUTParticipantIDType	ParticipantID;
	///�Ƿ��Ծ
	TUTBoolType	IsActive;
};
///E+1����Ȩ����
struct CUTExecFreezeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��ĺ�Լ����
	TUTInstrumentIDType	InstrumentID;
	///�ֲֶ�շ���
	TUTPosiDirectionType	PosiDirection;
	///��Ȩ����
	TUTOptionsTypeType	OptionsType;
	///���������_��λ��
	TUTVolumeType	Volume;
	///������
	TUTMoneyType	FrozenAmount;
};
///���ί������
struct CUTL2OrderField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��Ȼ��
	TUTDateType	ActionDay;
	///ʱ��
	TUTTimeType	Time;
	///�������Ƶ��
	TUTChannelNoType	ChannelNo;
	///���
	TUTSequenceNoType	SequenceNo;
	///�۸�
	TUTPriceType	Price;
	///����
	TUTVolumeType	Volume;
	///��������
	TUTDirectionType	Direction;
	///�۸�����
	TUTOrderPriceTypeType	OrderPriceType;
};
///��ʳɽ�����
struct CUTL2TradeField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��Ȼ��
	TUTDateType	ActionDay;
	///ʱ��
	TUTTimeType	Time;
	///�������Ƶ��
	TUTChannelNoType	ChannelNo;
	///���
	TUTSequenceNoType	SequenceNo;
	///�۸�
	TUTPriceType	Price;
	///����
	TUTVolumeType	Volume;
	///�ɽ����
	TUTTradeExecTypeType	TradeExecType;
	///�����̱�־
	TUTBSFlagType	BSFlag;
	///��ί�����
	TUTSequenceNoType	BidSequenceNo;
	///����ί�����
	TUTSequenceNoType	AskSequenceNo;
};
///������
struct CUTMainCenterField
{
	///�����ĺ�
	TUTDRIdentityIDType	DRIdentityID;
};
///���ײ���
struct CUTTradeParamField
{
	///��������
	TUTTradeParamIDType	TradeParamID;
	///��������ֵ
	TUTTradeParamValueType	TradeParamValue;
};
///�ն���֤����
struct CUTAuthPasswordField
{
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
	///�û�����֤��
	TUTPasswordType	UserProductPassword;
};
///�ͻ�����֤��Ȩ��
struct CUTAuthInvestorField
{
	///Ͷ���߷�Χ
	TUTInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
};
///�ն�IP���Ʊ�
struct CUTAuthIPField
{
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
	///IP��ַ
	TUTIPAddressType	IPAddress;
	///IP��ַ����
	TUTIPAddressType	IPMask;
	///Mac��ַ
	TUTMacAddressType	MacAddress;
};
///��Լ����ģʽ
struct CUTInstrumentTradingModeField
{
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����ģʽ
	TUTTradingModeType	TradingMode;
};
///Ͷ���ߺ�Լ����Ȩ��
struct CUTInstrumentTradingRightField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TUTInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///����Ȩ��
	TUTTradingRightType	TradingRight;
};
///����ʱ��
struct CUTMarketDataUpdateTimeField
{
	///��Ȼ��
	TUTDateType	ActionDay;
	///����޸�ʱ��
	TUTTimeType	UpdateTime;
};
///��̬����
struct CUTMarketDataStaticField
{
	///����
	TUTPriceType	OpenPrice;
	///������
	TUTPriceType	ClosePrice;
	///���ν����;����Ϊʵʱ�ο���ֵ
	TUTPriceType	SettlementPrice;
	///��߼�
	TUTPriceType	HighestPrice;
	///��ͼ�
	TUTPriceType	LowestPrice;
	///��Լ����״̬
	TUTInstrumentStatusType	InstrumentStatus;
};
///�������³ɽ�
struct CUTMarketDataLastMatchField
{
	///���¼�
	TUTPriceType	LastPrice;
	///����
	TUTLargeVolumeType	Volume;
	///�ɽ����
	TUTMoneyType	Turnover;
	///�ֲ���
	TUTLargeVolumeType	OpenInterest;
};
///��������
struct CUTMarketDataBestPriceField
{
	///�����һ
	TUTIntPriceType	BidPrice1;
	///������һ
	TUTIntPriceType	AskPrice1;
	///������һ
	TUTLargeVolumeType	BidVolume1;
	///������һ
	TUTLargeVolumeType	AskVolume1;
};
///��������
struct CUTL2MarketDataBestPriceField
{
	///�����һ
	TUTIntPriceType	BidPrice1;
	///������һ
	TUTIntPriceType	AskPrice1;
	///������һ
	TUTLargeVolumeType	BidVolume1;
	///������һ
	TUTLargeVolumeType	AskVolume1;
	///���򱨵���һ
	TUTVolumeType	BidOrderVolume1;
	///����������һ
	TUTVolumeType	AskOrderVolume1;
};
///������Ҫ�ĸ�������
struct CUTMarketDataForKernelField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��Ȼ��
	TUTDateType	ActionDay;
	///����޸�ʱ��
	TUTTimeType	UpdateTime;
	///��Լ����״̬
	TUTInstrumentStatusType	InstrumentStatus;
	///���¼�
	TUTPriceType	LastPrice;
};
///�䶯��L2����
struct CUTVariableL2DepthMarketDataField
{
	///��Ȼ��
	TUTDateType	ActionDay;
	///����޸�ʱ��
	TUTTimeType	UpdateTime;
	///����
	TUTIntPriceType	OpenPrice;
	///������
	TUTIntPriceType	ClosePrice;
	///���ν����;����Ϊʵʱ�ο���ֵ
	TUTIntPriceType	SettlementPrice;
	///��߼�
	TUTIntPriceType	HighestPrice;
	///��ͼ�
	TUTIntPriceType	LowestPrice;
	///��Լ����״̬
	TUTInstrumentStatusType	InstrumentStatus;
	///���¼�
	TUTIntPriceType	LastPrice;
	///����
	TUTLargeVolumeType	Volume;
	///�ɽ����
	TUTMoneyType	Turnover;
	///�ֲ���
	TUTLargeVolumeType	OpenInterest;
	///�����һ
	TUTIntPriceType	BidPrice1;
	///������һ
	TUTIntPriceType	AskPrice1;
	///������һ
	TUTLargeVolumeType	BidVolume1;
	///������һ
	TUTLargeVolumeType	AskVolume1;
	///���򱨵���һ
	TUTVolumeType	BidOrderVolume1;
	///����������һ
	TUTVolumeType	AskOrderVolume1;
};
///�䶯������
struct CUTVariableDepthMarketDataField
{
	///��Ȼ��
	TUTDateType	ActionDay;
	///����޸�ʱ��
	TUTTimeType	UpdateTime;
	///����
	TUTIntPriceType	OpenPrice;
	///������
	TUTIntPriceType	ClosePrice;
	///���ν����;����Ϊʵʱ�ο���ֵ
	TUTIntPriceType	SettlementPrice;
	///��߼�
	TUTIntPriceType	HighestPrice;
	///��ͼ�
	TUTIntPriceType	LowestPrice;
	///��Լ����״̬
	TUTInstrumentStatusType	InstrumentStatus;
	///���¼�
	TUTIntPriceType	LastPrice;
	///����
	TUTLargeVolumeType	Volume;
	///�ɽ����
	TUTMoneyType	Turnover;
	///�ֲ���
	TUTLargeVolumeType	OpenInterest;
	///�����һ
	TUTIntPriceType	BidPrice1;
	///������һ
	TUTIntPriceType	AskPrice1;
	///������һ
	TUTLargeVolumeType	BidVolume1;
	///������һ
	TUTLargeVolumeType	AskVolume1;
	///����۶�
	TUTIntPriceType	BidPrice2;
	///�����۶�
	TUTIntPriceType	AskPrice2;
	///��������
	TUTLargeVolumeType	BidVolume2;
	///��������
	TUTLargeVolumeType	AskVolume2;
	///�������
	TUTIntPriceType	BidPrice3;
	///��������
	TUTIntPriceType	AskPrice3;
	///��������
	TUTLargeVolumeType	BidVolume3;
	///��������
	TUTLargeVolumeType	AskVolume3;
	///�������
	TUTIntPriceType	BidPrice4;
	///��������
	TUTIntPriceType	AskPrice4;
	///��������
	TUTLargeVolumeType	BidVolume4;
	///��������
	TUTLargeVolumeType	AskVolume4;
	///�������
	TUTIntPriceType	BidPrice5;
	///��������
	TUTIntPriceType	AskPrice5;
	///��������
	TUTLargeVolumeType	BidVolume5;
	///��������
	TUTLargeVolumeType	AskVolume5;
};
///��������
struct CUTCenterField
{
	///���ĺ�
	TUTCenterIDType	CenterID;
	///��������
	TUTCenterNameType	CenterName;
};
///ϯλ�뽻�����Ķ�Ӧ��ϵ
struct CUTTraderCenterField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ĺ�
	TUTCenterIDType	CenterID;
};
///�ʽ����
struct CUTFundDistributionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///�������
	TUTRatioType	Ratio;
};
///˰��
struct CUTTaxRateField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///����˰��
	TUTRatioType	OpenTaxRatioByMoney;
	///����˰��
	TUTRatioType	OpenTaxRatioByVolume;
	///ƽ��˰��
	TUTRatioType	CloseTaxRatioByMoney;
	///ƽ��˰��
	TUTRatioType	CloseTaxRatioByVolume;
	///�����Ѱ�����
	TUTMoneyType	CommByOrder;
	///ÿ�ʱ������������(������CommByOrder)
	TUTMoneyType	MinCommByOrder;
};
///Ͷ������Ȩ��Լ����Ȩ��
struct CUTOptionInstrTradingRightField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���߷�Χ
	TUTInvestorRangeType	InvestorRange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�ֲַ���
	TUTPosiDirectionType	PosiDirection;
	///����Ȩ��
	TUTTradingRightType	TradingRight;
};
///��Ȩ��֤���㷨
struct CUTOptionMarginAlgoField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Ĵ���
	TUTInstrumentIDType	InstrumentID;
	///��ֵ���Żݱ���,������ȨΪ����1
	TUTRatioType	OutRatio;
	///��ͱ���ϵ��,������ȨΪ����2
	TUTRatioType	GuaranteeRatio;
};
///��ǰʱ��
struct CUTCurrentTimeField
{
	///��ǰ����
	TUTDateType	CurrDate;
	///��ǰʱ��
	TUTTimeType	CurrTime;
	///ҵ������
	TUTDateType	ActionDay;
};
///��Ӧ��Ϣ
struct CUTRspInfoField
{
	///�������
	TUTErrorIDType	ErrorID;
	///������Ϣ
	TUTErrorMsgType	ErrorMsg;
};
///��������
struct CUTSettlementRefField
{
	///������
	TUTDateType	TradingDay;
};
///�ֹ������
struct CUTSyncDepositField
{
	///�������ˮ��
	TUTDepositSeqNoType	DepositSeqNo;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///�����
	TUTMoneyType	Deposit;
	///�Ƿ�ǿ�ƽ���
	TUTBoolType	IsForce;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///�˻�����
	TUTAccTypeType	AccType;
};
///���͹�˾�û�����Ȩ��
struct CUTBrokerUserFunctionField
{
	///�û�����
	TUTUserIDType	UserID;
	///���͹�˾���ܴ���
	TUTBrokerFunctionCodeType	BrokerFunctionCode;
};
///������
struct CUTTradingDayField
{
	///������
	TUTDateType	TradingDay;
};
///ͬ���ֲ�
struct CUTSyncInvestorPositionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�ֲֶ�շ���
	TUTPosiDirectionType	PosiDirection;
	///��ֲ�
	TUTLargeVolumeType	YdPosition;
};
///����
struct CUTOrderField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTOrderRefType	OrderRef;
	///��������
	TUTDirectionType	Direction;
	///��ƽ��־
	TUTOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�����۸�����
	TUTOrderPriceTypeType	OrderPriceType;
	///����
	TUTVolumeType	VolumeTotalOriginal;
	///�۸�
	TUTPriceType	LimitPrice;
	///��Ч������
	TUTTimeConditionType	TimeCondition;
	///�ɽ�������
	TUTVolumeConditionType	VolumeCondition;
	///��������
	TUTContingentConditionType	ContingentCondition;
	///GTD����
	TUTDateType	GTDDate;
	///��С�ɽ���
	TUTVolumeType	MinVolume;
	///�Զ������־
	TUTBoolType	IsAutoSuspend;
	///�û�ǿ����־
	TUTBoolType	UserForceClose;
	///ֹ���
	TUTPriceType	StopPrice;
	///��������־
	TUTBoolType	IsSwapOrder;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	OrderLocalID;
	///��Ա����
	TUTParticipantIDType	ParticipantID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///������
	TUTDateType	TradingDay;
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///��װ���
	TUTInstallIDType	InstallID;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
	///�������
	TUTOrderSysIDType	OrderSysID;
	///����״̬
	TUTOrderStatusType	OrderStatus;
	///��������
	TUTOrderTypeType	OrderType;
	///��ɽ�����
	TUTVolumeType	VolumeTraded;
	///ʣ������
	TUTVolumeType	VolumeTotal;
	///��������
	TUTDateType	InsertDate;
	///ί��ʱ��
	TUTTimeType	InsertTime;
	///����ʱ��
	TUTTimeType	CancelTime;
	///���
	TUTSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
};
///��Լ����״̬
struct CUTInstrumentStatusField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��Լ����״̬
	TUTInstrumentStatusType	InstrumentStatus;
	///���뱾״̬ʱ��
	TUTTimeType	EnterTime;
	///���뱾״̬ԭ��
	TUTInstStatusEnterReasonType	EnterReason;
	///���
	TUTSequenceNoType	SequenceNo;
};
///�ɽ�
struct CUTTradeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTOrderRefType	OrderRef;
	///�ɽ����
	TUTTradeIDType	TradeID;
	///��������
	TUTDirectionType	Direction;
	///�������
	TUTOrderSysIDType	OrderSysID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///��ƽ��־
	TUTOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�۸�
	TUTPriceType	Price;
	///����
	TUTVolumeType	Volume;
	///�ɽ�ʱ��
	TUTDateType	TradeDate;
	///�ɽ�ʱ��
	TUTTimeType	TradeTime;
	///�ɽ�����
	TUTTradeTypeType	TradeType;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	OrderLocalID;
	///���
	TUTSequenceNoType	SequenceNo;
	///������
	TUTDateType	TradingDay;
	///���̰�װ���
	TUTInstallIDType	InstallID;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
};
///��������
struct CUTOrderActionField
{
	///������������
	TUTOrderRefType	OrderActionRef;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///��������
	TUTOrderRefType	OrderRef;
	///������־
	TUTActionFlagType	ActionFlag;
	///�۸�
	TUTPriceType	LimitPrice;
	///�����仯
	TUTVolumeType	VolumeChange;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///�������
	TUTOrderSysIDType	OrderSysID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTDateType	ActionDate;
	///����ʱ��
	TUTTimeType	ActionTime;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	OrderLocalID;
	///�������ر��
	TUTOrderLocalIDType	ActionLocalID;
	///��Ա����
	TUTParticipantIDType	ParticipantID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///��������״̬
	TUTOrderActionStatusType	OrderActionStatus;
	///��������
	TUTDirectionType	Direction;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///��������
	TUTOrderTypeType	OrderType;
	///��װ���
	TUTInstallIDType	InstallID;
	///������������Ϣ
	TUTExchangeErrorIDType	ExchangeErrorID;
	///����ǰ�ñ��
	TUTFrontIDType	ActionFrontID;
	///�����Ự���
	TUTSessionIDType	ActionSessionID;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///���뱨��
struct CUTInputOrderField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTOrderRefType	OrderRef;
	///��������
	TUTDirectionType	Direction;
	///��ƽ��־
	TUTOffsetFlagType	OffsetFlag;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///�����۸�����
	TUTOrderPriceTypeType	OrderPriceType;
	///����
	TUTVolumeType	VolumeTotalOriginal;
	///�۸�
	TUTPriceType	LimitPrice;
	///��Ч������
	TUTTimeConditionType	TimeCondition;
	///�ɽ�������
	TUTVolumeConditionType	VolumeCondition;
	///��������
	TUTContingentConditionType	ContingentCondition;
	///GTD����
	TUTDateType	GTDDate;
	///��С�ɽ���
	TUTVolumeType	MinVolume;
	///�Զ������־
	TUTBoolType	IsAutoSuspend;
	///�û�ǿ����־
	TUTBoolType	UserForceClose;
	///ֹ���
	TUTPriceType	StopPrice;
	///��������־
	TUTBoolType	IsSwapOrder;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///���뱨��
struct CUTInputOrderActionField
{
	///������������
	TUTOrderRefType	OrderActionRef;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///��������
	TUTOrderRefType	OrderRef;
	///������־
	TUTActionFlagType	ActionFlag;
	///�۸�
	TUTPriceType	LimitPrice;
	///�����仯
	TUTVolumeType	VolumeChange;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///�û��Ự
struct CUTUserSessionField
{
	///�û�����
	TUTUserIDType	UserID;
	///����
	TUTPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
	///�û�����֤��
	TUTPasswordType	UserProductPassword;
	///��̬����
	TUTPasswordType	OneTimePassword;
	///��¼��ע
	TUTLoginRemarkType	LoginRemark;
	///Mac��ַ
	TUTMacAddressType	MacAddress;
	///�ն�IP��ַ
	TUTIPAddressType	IPAddress;
	///˽�������
	TUTSequenceNoType	PrivateSeq;
	///���������
	TUTSequenceNoType	PublicSeq;
	///˽����������
	TUTDateType	TradingDay;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///��¼ʱ��
	TUTTimeType	LoginTime;
	///ϵͳ����
	TUTSystemNameType	SystemName;
	///�û�����
	TUTUserTypeType	UserType;
	///�Ƿ��ѵ�¼
	TUTBoolType	IsLogin;
	///�˿�
	TUTIPPortType	Port;
	///�ն���Ϣ(Ӳ�����к�32+����IP15)
	TUTOriTerminalInfoType	OriTerminalInfo;
};
///�û���¼Ӧ��
struct CUTRspLoginField
{
	///������
	TUTDateType	TradingDay;
	///��¼�ɹ�ʱ��
	TUTTimeType	LoginTime;
	///�û�����
	TUTUserIDType	UserID;
	///����ϵͳ����
	TUTSystemNameType	SystemName;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///˽�������
	TUTSequenceNoType	PrivateSeq;
	///���������
	TUTSequenceNoType	PublicSeq;
	///�鲥��ַ
	TUTMultiAddressType	MultiAddress;
};
///���ĵĺ�Լ
struct CUTSubInstrumentField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///ָ��¼��
struct CUTInputDesignateField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///ָ���Ǽ�����
	TUTOrderRefType	DesignateRef;
	///ָ������
	TUTDesignateTypeType	DesignateType;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///����ת�й�ת�뽻��Ա����
	TUTTraderIDType	TransfereeTraderID;
	///���ڳ���ת�йܱ��غ�
	TUTTraderIDType	OriDesignateLocalID;
};
///ָ��
struct CUTDesignateField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///ָ���Ǽ�����
	TUTOrderRefType	DesignateRef;
	///ָ������
	TUTDesignateTypeType	DesignateType;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///����ָ�����
	TUTOrderLocalIDType	DesignateLocalID;
	///��Ա����
	TUTParticipantIDType	ParticipantID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///ָ��/ת�й�״̬
	TUTDesignateStatusType	DesignateStatus;
	///������
	TUTDateType	TradingDay;
	///��������
	TUTDateType	InsertDate;
	///����ʱ��
	TUTTimeType	InsertTime;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///���
	TUTSequenceNoType	SequenceNo;
	///��װ���
	TUTInstallIDType	InstallID;
	///����ת�й�ת�뽻��Ա����
	TUTTraderIDType	TransfereeTraderID;
	///���ڱ�����ת�йܱ��غ�
	TUTOrderLocalIDType	OriDesignateLocalID;
};
///�û��ǳ�����
struct CUTReqLogoutField
{
	///�û�����
	TUTUserIDType	UserID;
};
///���������ر���
struct CUTExchangeOrderField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	OrderLocalID;
	///��������
	TUTDirectionType	Direction;
	///�������
	TUTOrderSysIDType	OrderSysID;
	///����״̬
	TUTOrderStatusType	OrderStatus;
	///ʣ������
	TUTVolumeType	VolumeTotal;
	///��������
	TUTDateType	InsertDate;
	///ί��ʱ��
	TUTTimeType	InsertTime;
	///������������Ϣ
	TUTExchangeErrorIDType	ExchangeErrorID;
	///��װ���
	TUTInstallIDType	InstallID;
	///���
	TUTSequenceNoType	SequenceNo;
	///�۸�
	TUTPriceType	LimitPrice;
};
///���������ر�������
struct CUTExchangeOrderActionField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	ActionLocalID;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
};
///����������ָ��
struct CUTExchangeDesignateField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///����ָ�����
	TUTOrderLocalIDType	DesignateLocalID;
	///ָ��״̬
	TUTDesignateStatusType	DesignateStatus;
	///��������
	TUTDateType	InsertDate;
	///ί��ʱ��
	TUTTimeType	InsertTime;
	///���
	TUTSequenceNoType	SequenceNo;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
	///��װ���
	TUTInstallIDType	InstallID;
};
///��ֹ��¼�û�IP
struct CUTLoginForbiddenUserIPField
{
	///�û�����
	TUTUserIDType	UserID;
	///IP��ַ
	TUTIPAddressType	IPAddress;
};
///IP�б�
struct CUTIPListField
{
	///IP��ַ
	TUTIPAddressType	IPAddress;
	///�Ƿ������
	TUTBoolType	IsWhite;
};
///ͬ�������
struct CUTSyncRandomStringField
{
	///�����
	TUTRandomStringType	RandomString;
	///��������
	TUTRandomStringTypeType	RandomStringType;
};
///ǿ���û��ǳ�
struct CUTForceUserLogoutField
{
	///�û�����
	TUTUserIDType	UserID;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///�Ƿ��������µ�¼
	TUTBoolType	EnableRelogin;
};
///�û��Ự����
struct CUTUserSessionRefField
{
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
};
///�û�������¼ʧ�ܴ���
struct CUTUserLoginFailedNumField
{
	///�û�����
	TUTUserIDType	UserID;
	///IP��ַ
	TUTIPAddressType	IPAddress;
	///������¼ʧ�ܴ���
	TUTVolumeType	Volume;
};
///IP��¼ʧ�ܴ���
struct CUTIPLoginFailedNumField
{
	///IP��ַ
	TUTIPAddressType	IPAddress;
	///������¼ʧ�ܴ���
	TUTVolumeType	Volume;
};
///�û�������
struct CUTUserPasswordUpdateField
{
	///�û�����
	TUTUserIDType	UserID;
	///ԭ���Ŀ���
	TUTPasswordType	OldPassword;
	///�µĿ���
	TUTPasswordType	NewPassword;
};
///����ת��
struct CUTInputTransferField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///ת������
	TUTOrderRefType	TransferRef;
	///ת������
	TUTTransferTypeType	TransferType;
	///���
	TUTMoneyType	Deposit;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///�˻�����
	TUTAccTypeType	AccType;
	///���д���
	TUTBankIDType	BankID;
	///�ʽ�����
	TUTPasswordType	FundPassword;
	///��������
	TUTPasswordType	BankPassword;
};
///ת��
struct CUTTransferField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///ת������
	TUTOrderRefType	TransferRef;
	///ת������
	TUTTransferTypeType	TransferType;
	///���
	TUTMoneyType	Deposit;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///�˻�����
	TUTAccTypeType	AccType;
	///���д���
	TUTBankIDType	BankID;
	///�ʽ�����
	TUTPasswordType	FundPassword;
	///��������
	TUTPasswordType	BankPassword;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///����ת�˺�
	TUTOrderLocalIDType	TransferLocalID;
	///ת��ϵͳ��
	TUTOrderSysIDType	TransferSysID;
	///ת��״̬
	TUTTransferStatusType	TransferStatus;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
	///ת������
	TUTDateType	InsertDate;
	///ת��ʱ��
	TUTTimeType	InsertTime;
};
///����������ת��
struct CUTExchangeTransferField
{
	///����ת�˺�
	TUTOrderLocalIDType	TransferLocalID;
	///ת��ϵͳ��
	TUTOrderSysIDType	TransferSysID;
	///ת��״̬
	TUTTransferStatusType	TransferStatus;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
};
///��������
struct CUTSubTopicField
{
	///����
	TUTSubjectIDType	SubjectID;
	///���
	TUTSequenceNoType	SequeceNo;
	///������
	TUTDateType	TradingDay;
};
///������������
struct CUTSubMDTopicField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///���ĵ���������,��ʹ��|����
	TUTSubDataTypeType	SubDataType;
};
///���ָ��
struct CUTMonitorIndexField
{
	///δ֪����ʱns(3�����һ��)
	TUTLargeVolumeType	DelayTimeUnknown;
	///�ѱ�����ʱns(3�����һ��)
	TUTLargeVolumeType	DelayTimeQueued;
	///���󱨵���
	TUTLargeVolumeType	ErrOrderVolume;
	///���󳷵���
	TUTLargeVolumeType	ErrOrderActionVolume;
	///���󱨵�Ͷ���ߴ���
	TUTInvestorIDType	ErrOrderInvestorID;
	///���󳷵�Ͷ���ߴ���
	TUTInvestorIDType	ErrOrderActionInvestorID;
	///��ʱ��ʱ���
	TUTTimeType	Time;
};
///�ն���Ϣ¼��
struct CUTSubmitTerminalInfoField
{
	///�û�����
	TUTUserIDType	UserID;
	///��¼���,��1��ʼ���;����Ա����תʱ�ڱ���¼����Ҳ��ָ��
	TUTSequenceNoType	LoginSeq;
	///�ն���Ϣ(MA;LIP=XXX)
	TUTTerminalInfoType	TerminalInfo;
};
///�ն���Ϣ
struct CUTTerminalInfoField
{
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///�û�����
	TUTUserIDType	UserID;
	///��¼���
	TUTSequenceNoType	LoginSeq;
	///�ն���Ϣ(#OSTPMA;IIP=XXX)
	TUTTerminalInfoType	TerminalInfo;
};
///��ѯ����µ���
struct CUTMaxOrderVolumeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///��������
	TUTDirectionType	Direction;
	///��ƽ��־
	TUTOffsetFlagType	OffsetFlag;
	///�����۸�
	TUTPriceType	Price;
	///�������������
	TUTVolumeType	MaxVolume;
	///ԭʼ�������������
	TUTLargeVolumeType	MaxVolumeOri;
};
///����ֱ�ӻ���
struct CUTInputFundPaybackField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///ֱ�ӻ�������
	TUTOrderRefType	FundPaybackRef;
	///������
	TUTMoneyType	Amount;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///ֱ�ӻ���
struct CUTFundPaybackField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///ֱ�ӻ�������
	TUTOrderRefType	FundPaybackRef;
	///������
	TUTMoneyType	Amount;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///����ת�˺�
	TUTOrderLocalIDType	FundPaybackLocalID;
	///ֱ�ӻ�������
	TUTDateType	InsertDate;
	///ֱ�ӻ���ʱ��
	TUTTimeType	InsertTime;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///����ֱ�ӻ�ȯ
struct CUTInputStockPaybackField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///ֱ�ӻ�ȯ����
	TUTOrderRefType	StockPaybackRef;
	///ֱ�ӻ�ȯ����
	TUTLargeVolumeType	Volume;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///ֱ�ӻ�ȯ
struct CUTStockPaybackField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///ֱ�ӻ�ȯ����
	TUTOrderRefType	StockPaybackRef;
	///ֱ�ӻ�ȯ����
	TUTLargeVolumeType	Volume;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///����ֱ�ӻ�ȯ��
	TUTOrderLocalIDType	StockPaybackLocalID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///��װ���
	TUTInstallIDType	InstallID;
	///ֱ�ӻ�ȯ����
	TUTDateType	InsertDate;
	///ֱ�ӻ�ȯʱ��
	TUTTimeType	InsertTime;
	///ֱ�ӻ�ȯϵͳ��
	TUTOrderSysIDType	StockPaybackSysID;
	///ֱ�ӻ�ȯ״̬
	TUTOrderActionStatusType	StockPaybackStatus;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///����������ֱ�ӻ�ȯ
struct CUTExchangeStockPaybackField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///����ֱ�ӻ�ȯ��
	TUTOrderLocalIDType	StockPaybackLocalID;
	///ֱ�ӻ�ȯϵͳ��
	TUTOrderSysIDType	StockPaybackSysID;
	///ֱ�ӻ�ȯ״̬
	TUTOrderActionStatusType	StockPaybackStatus;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
	///��װ���
	TUTInstallIDType	InstallID;
};
///�������ʶ��
struct CUTPublicCreditFundField
{
	///�������ʶ��
	TUTMoneyType	TotalAmount;
	///��ռ�ö��
	TUTMoneyType	FrozenAmount;
};
///����ӯ��
struct CUTPositionProfitForKernelField
{
	///�ʽ�װ���
	TUTInstallIDType	AccountInstallID;
	///�ֲ�ӯ��,������ȨΪʵʱ��֤��
	TUTMoneyType	PositionProfit;
};
///Ͷ����������ϸ
struct CUTCreditFundDetailField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTDateType	OpenDate;
	///��ˮ��
	TUTTradeIDType	TradeID;
	///������
	TUTDateType	ExpireDate;
	///���ʽ��
	TUTMoneyType	Amount;
	///�ѹ黹���ʽ��
	TUTMoneyType	AmountPayback;
	///������������
	TUTVolumeType	Volume;
	///�ѹ黹��������
	TUTMoneyType	VolumePayback;
	///��黹���ʽ��
	TUTMoneyType	YdAmountPayback;
	///����������(���ɻ�)
	TUTMoneyType	Commission;
	///������ȯ������
	TUTMoneyType	CreditAmountPayback;
	///����ֱ�ӻ�����
	TUTMoneyType	FundAmountPayback;
};
///Ͷ������ȯ��ϸ
struct CUTCreditStockDetailField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��ȯ����
	TUTDateType	OpenDate;
	///��ˮ��
	TUTTradeIDType	TradeID;
	///������
	TUTDateType	ExpireDate;
	///��ȯ����
	TUTVolumeType	Volume;
	///�ѹ黹��ȯ����
	TUTVolumeType	VolumePayback;
	///��ȯ�������
	TUTMoneyType	Amount;
	///�ѹ黹��ȯ���
	TUTMoneyType	AmountPayback;
};
///���ú�Լ����
struct CUTCreditInstrumentField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��Ʊ������
	TUTRatioType	ConvertRate;
	///�Ƿ������
	TUTBoolType	IsCreditFund;
	///�Ƿ����ȯ
	TUTBoolType	IsCreditStock;
	///�Ƿ񵣱�Ʒ
	TUTBoolType	IsGuarantee;
	///�Ƿ����֤ͨȯ
	TUTBoolType	IsLiquid;
	///���жȷ������
	TUTInstrumentIDType	ConcentrationGroupID;
	///���ʼ۸�
	TUTMoneyType	AssetPrice;
	///��ȯ���ʼ۸�
	TUTMoneyType	AssetPriceCreditStock;
};
///Ͷ����������Ϣ
struct CUTCreditInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///���ʱ�֤����
	TUTRatioType	FundRate;
	///��ȯ��֤����
	TUTRatioType	StockRate;
	///ά�ֵ�����
	TUTRatioType	GuaranteeRate;
	///������ȯ�ܶ��
	TUTMoneyType	TotalLimit;
	///��ȯ���
	TUTMoneyType	StockLimit;
	///���ʶ��
	TUTMoneyType	FundLimit;
	///˽�����ʶ��
	TUTMoneyType	PrivateCreditFund;
};
///˽����ȯ���
struct CUTPrivateCreditStockField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///����ȯ����
	TUTLargeVolumeType	Volume;
	///��ʼ����
	TUTDateType	BeginDate;
	///��������
	TUTDateType	EndDate;
	///����ȯ����(������)
	TUTLargeVolumeType	ReserveVolume;
};
///�����˻�����ͨ�˻���Ӧ��
struct CUTCreditToNormalInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��ͨͶ���ߴ���
	TUTInvestorIDType	NormalInvestorID;
	///��ͨ�ͻ�����
	TUTClientIDType	NormalClientID;
};
///���жȲ���
struct CUTCreditConcentrationField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///���ж�ҵ������
	TUTConcentrationBizTypeType	ConcentrationBizType;
	///���жȺ�Լ����
	TUTConcentrationInstrTypeType	ConcentrationInstrType;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����(С��/����)
	TUTInstrumentIDType	InstrumentID;
	///ά�ֵ���������
	TUTRatioType	GuaranteeRateLower;
	///ά�ֵ���������
	TUTRatioType	GuaranteeRateUpper;
	///���ж�
	TUTRatioType	ConcentrationRate;
};
///ETF������Ϣ
struct CUTETFInfoField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///һ���г��������
	TUTFundIDType	RedemptionID;
	///ÿ�����Ӷ�Ӧ��ETF����,�������������
	TUTVolumeType	CreationRedemptionUnit;
	///����ֽ��������
	TUTRatioType	MaxCashRatio;
	///�Ƿ���Ҫ����IOPV
	TUTBoolType	PublishIOPV;
	///�Ƿ���깺
	TUTBoolType	Creation;
	///�Ƿ�����
	TUTBoolType	Redemption;
	///�ɷ�֤ȯ����
	TUTVolumeType	RecordNum;
	///T��ÿ�����ӵ�Ԥ���ֽ���
	TUTMoneyType	EstimateCashComponent;
	///ǰһ����С���굥λ��ֵ
	TUTMoneyType	NAVperCU;
	///ǰһ�ջ���ݶֵ
	TUTMoneyType	NAV;
	///�����ֽ�������
	TUTMoneyType	SubstituteAmount;
	///��سɷֹɹ���
	TUTVolumeType	RedemptionStockVolume;
};
///ETF�ɷֹ�
struct CUTETFComponentField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///ETF����
	TUTFundIDType	ETFID;
	///�ɷֹɺ�Լ����
	TUTInstrumentIDType	InstrumentID;
	///�ɷֹɽ���������
	TUTExchangeIDType	ComponentExchangeID;
	///֤ȯ����
	TUTVolumeType	Volume;
	///�����־
	TUTSubstituteFlagType	SubstituteFlag;
	///�깺��۱���
	TUTRatioType	CreationPremiumRate;
	///����ۼ۱���
	TUTRatioType	RedemptionDiscountRate;
	///�깺������
	TUTMoneyType	CreationCashSubstitute;
	///���������
	TUTMoneyType	RedemptionCashSubstitute;
};
///����ӯ������
struct CUTPositionProfitForKernelRefField
{
	///�ʽ�װ���
	TUTInstallIDType	AccountInstallID;
	///֤ȯ��ֵ
	TUTMoneyType	CreditTotalValue;
	///��ȯ��ֵ
	TUTMoneyType	CreditStockValue;
	///��֤��������
	TUTMoneyType	CreditAvailableParam;
};
///����ӯ������1
struct CUTPositionProfitForKernelRef1Field
{
	///��װ���
	TUTInstallIDType	PositionInstallID;
	///֤ȯ��ֵ
	TUTMoneyType	Value;
};
///���жȳֲ�
struct CUTConcentrationPositionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///���жȺ�Լ����
	TUTConcentrationInstrTypeType	ConcentrationInstrType;
	///��ֵ(��������ֵ)
	TUTMoneyType	Value;
};
///�������¼�����
struct CUTMDLastPriceRefField
{
	///��������
	TUTVolumeType	MDInstallID;
	///���¼�
	TUTVolumeType	LastPrice;
};
///�ظ���
struct CUTDuplicateCountField
{
	///����
	TUTVolumeType	DuplicateCount;
};
///ͬ���������ʶ��
struct CUTSyncPublicCreditFundField
{
	///�������ʶ������
	TUTMoneyType	Amount;
};
///LocalID
struct CUTLocalIDField
{
	///����ת�˺�
	TUTOrderLocalIDType	TransferLocalID;
	///����ֱ�ӻ����
	TUTOrderLocalIDType	FundPaybackLocalID;
};
///���Ͷ����
struct CUTBoardInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///ռ����������
	TUTVolumeType	Volume;
};
///��֤����������ϸ
struct CUTCreditAvailableDetailField
{
	///Ͷ�����ʺ�
	TUTAccountIDType	AccountID;
	///����Ʒ����
	TUTMoneyType	CreditCollateralValue;
	///����ӯ��
	TUTMoneyType	CreditFundProfit;
	///��ȯӯ��
	TUTMoneyType	CreditStockProfit;
};
///������������
struct CUTGatewayField
{
	///����λ��(Ŀǰֻ����δ���ӵ�����)
	TUTLocationType	Location;
	///����������
	TUTExchangeIDType	ExchangeID;
};
///Ͷ���߷ּ�
struct CUTInvestorLevelField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///Ͷ���߷ּ�����
	TUTVolumeType	Level;
};
///ϵͳ����
struct CUTSystemNameField
{
	///ϵͳ����
	TUTSystemNameType	SystemName;
};
///��������
struct CUTInputLockField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTOrderRefType	LockRef;
	///����
	TUTVolumeType	Volume;
	///��������
	TUTLockTypeType	LockType;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///����
struct CUTLockField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTOrderRefType	LockRef;
	///����
	TUTVolumeType	Volume;
	///��������
	TUTLockTypeType	LockType;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///�����������
	TUTOrderLocalIDType	LockLocalID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///������
	TUTDateType	TradingDay;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///��װ���
	TUTInstallIDType	InstallID;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
	///�������
	TUTOrderSysIDType	LockSysID;
	///����״̬
	TUTOrderActionStatusType	LockStatus;
	///��������
	TUTDateType	InsertDate;
	///ί��ʱ��
	TUTTimeType	InsertTime;
	///����ʱ��
	TUTTimeType	CancelTime;
	///���
	TUTSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
};
///��������������
struct CUTExchangeLockField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	LockLocalID;
	///�������
	TUTOrderSysIDType	LockSysID;
	///����״̬
	TUTOrderActionStatusType	LockStatus;
	///��������
	TUTDateType	InsertDate;
	///ί��ʱ��
	TUTTimeType	InsertTime;
	///������������Ϣ
	TUTExchangeErrorIDType	ExchangeErrorID;
	///��װ���
	TUTInstallIDType	InstallID;
	///���
	TUTSequenceNoType	SequenceNo;
};
///������Ȩ
struct CUTInputExecOrderField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����;�ϲ���Ȩ����дP and C
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTOrderRefType	ExecOrderRef;
	///����
	TUTVolumeType	Volume;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///��Ȩ
struct CUTExecOrderField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����;�ϲ���Ȩ����дP and C
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTOrderRefType	ExecOrderRef;
	///����
	TUTVolumeType	Volume;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	ExecOrderLocalID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///������
	TUTDateType	TradingDay;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///��װ���
	TUTInstallIDType	InstallID;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
	///��Ȩ���
	TUTOrderSysIDType	ExecOrderSysID;
	///ִ�н��
	TUTExecResultType	ExecResult;
	///��������
	TUTDateType	InsertDate;
	///ί��ʱ��
	TUTTimeType	InsertTime;
	///����ʱ��
	TUTTimeType	CancelTime;
	///���
	TUTSequenceNoType	SequenceNo;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
};
///������������Ȩ
struct CUTExchangeExecOrderField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	ExecOrderLocalID;
	///�������
	TUTOrderSysIDType	ExecOrderSysID;
	///ִ�н��
	TUTExecResultType	ExecResult;
	///��������
	TUTDateType	InsertDate;
	///ί��ʱ��
	TUTTimeType	InsertTime;
	///������������Ϣ
	TUTExchangeErrorIDType	ExchangeErrorID;
	///��װ���
	TUTInstallIDType	InstallID;
	///���
	TUTSequenceNoType	SequenceNo;
};
///�ֲֶ���
struct CUTPosiFreezeField
{
	///���ױ���
	TUTClientIDType	ClientID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTPosiFreezeLocalIDType	PosiFreezeLocalID;
	///����
	TUTLargeVolumeType	Volume;
	///����ԭ��
	TUTFreezeReasonType	FreezeReason;
	///��������
	TUTFreezeTypeType	FreezeType;
	///��ˮ�е����
	TUTSequenceNoType	SequenceNo;
};
///������֤ȯ�ֲ�
struct CUTLockPositionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///����
	TUTLargeVolumeType	Volume;
	///��������,����δ֪��Ҳ�ᶳ�������
	TUTLargeVolumeType	FrozenVolume;
};
///��Ȩ����
struct CUTExecOrderActionField
{
	///��Ȩ��������
	TUTOrderRefType	ExecOrderActionRef;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///��Ȩ����
	TUTOrderRefType	ExecOrderRef;
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///�������
	TUTOrderSysIDType	ExecOrderSysID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��������
	TUTDateType	ActionDate;
	///����ʱ��
	TUTTimeType	ActionTime;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	ExecOrderLocalID;
	///�������ر��
	TUTOrderLocalIDType	ActionLocalID;
	///�ͻ�����
	TUTClientIDType	ClientID;
	///��������״̬
	TUTOrderActionStatusType	OrderActionStatus;
	///Ӫҵ�����
	TUTBranchIDType	BranchID;
	///��װ���
	TUTInstallIDType	InstallID;
	///������������Ϣ
	TUTExchangeErrorIDType	ExchangeErrorID;
	///����ǰ�ñ��
	TUTFrontIDType	ActionFrontID;
	///�����Ự���
	TUTSessionIDType	ActionSessionID;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///������Ȩ����
struct CUTInputExecOrderActionField
{
	///��Ȩ��������
	TUTOrderRefType	ExecOrderActionRef;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///��Ȩ����
	TUTOrderRefType	ExecOrderRef;
	///IP��ַ
	TUTIPAddressAsIntType	IPAddressAsInt;
	///Mac��ַ
	TUTMacAddressAsLongType	MacAddressAsLong;
};
///�������ֲֶ���
struct CUTExchangePosiFreezeField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���سֲֶ�����
	TUTPosiFreezeLocalIDType	PosiFreezeLocalID;
	///����ԭ��
	TUTFreezeReasonType	FreezeReason;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
};
///������������Ȩ����
struct CUTExchangeExecOrderActionField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
	///���ر������
	TUTOrderLocalIDType	ActionLocalID;
	///�������������
	TUTExchangeErrorIDType	ExchangeErrorID;
};
///��Ȩ�޲ֶ���
struct CUTOptPosiLimitField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///����������
	TUTLargeVolumeType	TotalVolume;
	///��ͷ��������
	TUTLargeVolumeType	LongVolume;
	///���տ�����������
	TUTLargeVolumeType	OpenVolume;
	///���ն�ͷ������������
	TUTLargeVolumeType	LongOpenVolume;
	///����������
	TUTLargeVolumeType	TotalVolumeFrozen;
	///��ͷ��������
	TUTLargeVolumeType	LongVolumeFrozen;
	///���տ�����������
	TUTLargeVolumeType	OpenVolumeFrozen;
	///���ն�ͷ������������
	TUTLargeVolumeType	LongOpenVolumeFrozen;
};
///��Ȩ������ƶ���
struct CUTOptAmountLimitField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��ͷ�ֲֽ������
	TUTMoneyType	LongAmount;
	///��ͷ�ֲֽ���
	TUTMoneyType	LongAmountFrozen;
};
///Dll����
struct CUTDllSettingField
{
	///Dll����
	TUTDllNameType	DllName;
	///�Ƿ�����
	TUTBoolType	Enable;
	///������Ϣ
	TUTErrorMsgType	ErrorMsg;
};
///Dll����
struct CUTDllUpdateField
{
	///Dll����
	TUTDllNameType	DllName;
	///���к�
	TUTSequenceNoType	SequenceNo;
	///����
	TUTContentType	Content;
	///����
	TUTVolumeType	Size;
	///������Ϣ
	TUTErrorMsgType	ErrorMsg;
};
///�����ڴ����ݿ�
struct CUTDataDumpField
{
	///������Ϣ
	TUTErrorMsgType	ErrorMsg;
};
///��Լ��ѯ
struct CUTQryInstrumentField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///�����ѯ
struct CUTQryDepthMarketDataField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///Ͷ���ֲֲ߳�ѯ
struct CUTQryInvestorPositionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///�ʽ��˺Ų�ѯ
struct CUTQryTradingAccountField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///���ִ���
	TUTCurrencyIDType	CurrencyID;
	///�˻�����
	TUTAccTypeType	AccType;
};
///������ѯ
struct CUTQryOrderField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��ʼ���
	TUTSequenceNoType	SequenceNo;
	///��SequenceNo��ʼ,��ѯLimit����¼
	TUTVolumeType	Limit;
	///����״̬,��ѯʱ��������״̬δ���(h),�����(i),�гɽ�(j):
	TUTOrderStatusType	OrderStatus;
};
///�ɽ���ѯ
struct CUTQryTradeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��ʼ���(������ѯ)
	TUTSequenceNoType	SequenceNo;
	///��SequenceNo��ʼ,��ѯLimit����¼
	TUTVolumeType	Limit;
};
///����Ա���̻���ѯ
struct CUTQryTraderField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///����������Ա����
	TUTTraderIDType	TraderID;
};
///��Ȩ��Լÿ�ֱ�֤���ʲ�ѯ
struct CUTQryOptionInstrMarginByVolumeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///��Ȩ��Լÿ�ֱ�֤����
struct CUTOptionInstrMarginByVolumeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///ÿ�ֺ�Լ��֤��
	TUTMoneyType	MarginByVolume;
};
///��Ȩ�������ʲ�ѯ
struct CUTQryOptionInstrCommRateField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///�������ˮ��ѯ
struct CUTQrySyncDepositField
{
	///�������ˮ��
	TUTDepositSeqNoType	DepositSeqNo;
};
///���͹�˾�û�Ȩ�޲�ѯ
struct CUTQryBrokerUserFunctionField
{
	///�û�����
	TUTUserIDType	UserID;
};
///�������ʲ�ѯ
struct CUTQryInstrumentCommissionRateField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///Ͷ���߲�ѯ
struct CUTQryInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///�û��Ự��ѯ
struct CUTQryUserSessionField
{
	///�û�����
	TUTUserIDType	UserID;
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
};
///ת�˲�ѯ
struct CUTQryTransferField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///�û������ѯ
struct CUTQryBrokerUserPasswordField
{
	///�û�����
	TUTUserIDType	UserID;
};
///��ѯ���ױ���
struct CUTQryTradingCodeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��ѯͶ���ߺ�Լ����Ȩ��
struct CUTQryInstrumentTradingRightField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��ѯ��֤����
struct CUTQryAuthPasswordField
{
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
};
///��ѯ�ͻ�����֤��Ȩ��
struct CUTQryAuthInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
};
///��ѯ�ն�IP���Ʊ�
struct CUTQryAuthIPField
{
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
};
///��ѯ�������
struct CUTQryL2OrderTradeField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///�������Ƶ��
	TUTChannelNoType	ChannelNo;
	///��ʼ���
	TUTSequenceNoType	SequenceNoBegin;
	///�������
	TUTSequenceNoType	SequenceNoEnd;
};
///��ѯָ��
struct CUTQryDesignateField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��ѯ��������
struct CUTQryOrderActionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///��ѯ��ֹ��¼�û�IP
struct CUTQryLoginForbiddenUserIPField
{
	///�û�����
	TUTUserIDType	UserID;
};
///��ѯIP�б�
struct CUTQryIPListField
{
	///IP��ַ
	TUTIPAddressType	IPAddress;
};
///��ѯ���ָ��
struct CUTQryMonitorIndexField
{
	///ʱ��
	TUTTimeType	Time;
};
///��ѯ�ն���Ϣ
struct CUTQryTerminalInfoField
{
	///ǰ�ñ��
	TUTFrontIDType	FrontID;
	///�Ự���
	TUTSessionIDType	SessionID;
	///��¼���
	TUTSequenceNoType	LoginSeq;
};
///��ѯ����µ���
struct CUTQryMaxOrderVolumeField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///Ͷ���ױ���־
	TUTHedgeFlagType	HedgeFlag;
	///��������
	TUTDirectionType	Direction;
	///��ƽ��־
	TUTOffsetFlagType	OffsetFlag;
	///�����۸�
	TUTPriceType	Price;
};
///���ú�Լ���Բ�ѯ
struct CUTQryCreditInstrumentField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///�����˻�����ͨ�˻���Ӧ���ѯ
struct CUTQryCreditToNormalInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///Ͷ����������Ϣ��ѯ
struct CUTQryCreditInvestorField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///˽����ȯ��Ȳ�ѯ
struct CUTQryPrivateCreditStockField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///���жȲ�����ѯ
struct CUTQryCreditConcentrationField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///Ͷ����������ϸ��ѯ
struct CUTQryCreditFundDetailField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///Ͷ������ȯ��ϸ��ѯ
struct CUTQryCreditStockDetailField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///Ͷ����ֱ�ӻ����ѯ
struct CUTQryFundPaybackField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///Ͷ����ֱ�ӻ�ȯ��ѯ
struct CUTQryStockPaybackField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///�������ʶ�Ȳ�ѯ
struct CUTQryPublicCreditFundField
{
	///ʱ��
	TUTTimeType	Time;
};
///ETF������Ϣ��ѯ
struct CUTQryETFInfoField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///ETF�ɷֹɲ�ѯ
struct CUTQryETFComponentField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///ETF����
	TUTFundIDType	ETFID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///MDB��ѯ
struct CUTQryMDBField
{
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///���жȳֲֲ�ѯ
struct CUTQryConcentrationPositionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��ѯ��֤����������ϸ
struct CUTQryCreditAvailableDetailField
{
	///Ͷ�����ʺ�
	TUTAccountIDType	AccountID;
};
///�����������Ӳ�ѯ
struct CUTQryGatewayField
{
	///ʱ��
	TUTTimeType	Time;
};
///��ѯͶ���߷ּ�
struct CUTQryInvestorLevelField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��ѯͶ������Ȩ��Լ����Ȩ��
struct CUTQryOptionInstrTradingRightField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///ϵͳ���Ʋ�ѯ
struct CUTQrySystemNameField
{
	///ϵͳ����
	TUTSystemNameType	SystemName;
};
///������ѯ
struct CUTQryLockField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��Ȩ��ѯ
struct CUTQryExecOrderField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///�ֲֶ����ѯ
struct CUTQryLockPositionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��Ȩ�޲ֶ����ѯ
struct CUTQryOptPosiLimitField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��Ȩ�޶���ѯ
struct CUTQryOptAmountLimitField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
};
///��Ȩ������ѯ
struct CUTQryExecOrderActionField
{
	///Ͷ���ߴ���
	TUTInvestorIDType	InvestorID;
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
};
///��Ȩ��֤���㷨��ѯ
struct CUTQryOptionMarginAlgoField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Ĵ���
	TUTInstrumentIDType	InstrumentID;
};


//L2������
struct TUTL2BidAskType
{
	///�����
	TUTPriceType	BidPrice;
	///������
	TUTPriceType	AskPrice;
	///������
	TUTLargeVolumeType	BidVolume;
	///������
	TUTLargeVolumeType	AskVolume;
	///���򱨵���
	TUTVolumeType	BidOrderVolume;
	///����������
	TUTVolumeType	AskOrderVolume;
};

///10������
struct CUTL2DepthMarketDataField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///������
	TUTDateType	TradingDay;
	///�ϴν����;����Ϊ��һ�վ�ֵ
	TUTPriceType	PreSettlementPrice;
	///������
	TUTPriceType	PreClosePrice;
	///��ֲ���
	TUTLargeVolumeType	PreOpenInterest;
	///��ͣ���
	TUTPriceType	UpperLimitPrice;
	///��ͣ���
	TUTPriceType	LowerLimitPrice;
	///��Ȼ��
	TUTDateType	ActionDay;
	///����޸�ʱ��
	TUTTimeType	UpdateTime;
	///����
	TUTPriceType	OpenPrice;
	///������
	TUTPriceType	ClosePrice;
	///���ν����;����Ϊʵʱ�ο���ֵ
	TUTPriceType	SettlementPrice;
	///��߼�
	TUTPriceType	HighestPrice;
	///��ͼ�
	TUTPriceType	LowestPrice;
	///��Լ����״̬
	TUTInstrumentStatusType	InstrumentStatus;
	///���¼�
	TUTPriceType	LastPrice;
	///����
	TUTLargeVolumeType	Volume;
	///�ɽ����
	TUTMoneyType	Turnover;
	///�ֲ���
	TUTLargeVolumeType	OpenInterest;
	//������
	TUTL2BidAskType BidAsk[10];
};

//L2ί�б�����ʾ����
struct TUTL2OrderVolumeType
{
	///����ί�б���
	TUTVolumeType	BidOrderVolume;
	///����ί�б���
	TUTVolumeType	AskOrderVolume;
};

///L2���ż�ί����ϸ
struct CUTL2BestOrderField
{
	///����������
	TUTExchangeIDType	ExchangeID;
	///��Լ����
	TUTInstrumentIDType	InstrumentID;
	///��Ȼ��
	TUTDateType	ActionDay;
	///����޸�ʱ��
	TUTTimeType	UpdateTime;
	///���������
	TUTPriceType	BidPrice;
	///����������
	TUTPriceType	AskPrice;
	///��ʾί����ϸ����
	TUTPriceLevelNumType	OrderNum;
	//ί�б�����ʾ
	TUTL2OrderVolumeType OrderVolume[50];
};

///�û���¼����
struct CUTReqLoginField
{
	///�û�����
	TUTUserIDType	UserID;
	///����
	TUTPasswordType	Password;
	///�û��˲�Ʒ��Ϣ
	TUTProductInfoType	UserProductInfo;
	///�û�����֤��
	TUTPasswordType	UserProductPassword;
	///��̬����
	TUTPasswordType	OneTimePassword;
	///��¼��ע
	TUTLoginRemarkType	LoginRemark;
};
