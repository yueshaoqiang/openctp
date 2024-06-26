# CTP程序接入东方财富EMT柜台

openctp已经发布了东方财富EMT柜台的CTPAPI兼容接口，以CTPAPI接口对EMT接口进行封装，使得CTP程序无需任何修改，只是更换一下CTP动态库，就可以接入东方财富柜台交易股票、债券、ETF期权等商品。

openctp的动态库（dll、so等文件）只是对东方财富接口的简单封装，不是经过模拟平台的模拟服务器进行转发，而是直接调用东方财富的dll与柜台进行交互，所以登录用户名、密码均为东方财富柜台用户名、密码，模拟账户申请需至东方财富EMT官网申请，该接入方式同样支持实盘。

东方财富EMT模拟平台是跟simnow类似的证券模拟平台，采用与CTPAPI类似形式的开放式API，更多信息请至官网了解：https://emt.18.cn/

## 用法：
在[openctp官网](http://www.openctp.cn/)下载相应CTPAPI版本的dll，交易dll有两个文件，thosttraderapi_se.dll为模拟平台的封装dll，emt_api.dll为东方财富发布的接口dll，行情也同样是有两个，交易与行情的dll互相独立，可以只接交易或只接行情。

下载相应的动态库，覆盖现有CTP程序相应动态库，测试环境地址为东方财富的7x24环境：

行情前置地址：tcp://61.152.230.216:8093

交易前置地址：tcp://61.152.230.41:19088

## 编译：

使用cmake管理跨平台编译，最外层目录下的cmake文件是个总体编译工程，各版本号目录下的为各版本的工程，均可编译。

例：（ctp2EMT目录下总体编译）
```shell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## 客户端：
openctp开发的交易客户端MiniTrader即是通过CTPAPI兼容接口的方式支持EMT柜台的，可在[openctp官网](http://www.openctp.cn/)下载使用。

**<u>注意：由于EMT的原生交易API不提供查询合约接口，且因接口设计限制不便在交易接口中整合行情接口，因此提供了一个合约字典文件，在仿CTPAPI的合约查询中，会通过读取该文件来响应合约查询应答，该文件（dict.csv）需要放在程序的运行目录下，基本与dll放在同一目录即可。</u>**

**<u>注意：EMT有个ClientID机制，客户端必须自己指定一个值（1~127），类似于CTP的AppID概念，因此就使用了AppID作为ClientID，AuthCode没有用到，空着即可。</u>**

**<u>注意：EMT接口允许多个终端同时在线，但是每个终端的ClientID不能一样，MiniTrader中默认配置的是100，请注意不要冲突。</u>**
