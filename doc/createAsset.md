## 数字资产发行手册

### 1.	 节点的安装（已安装节点， 可跳过此步骤）
1) 进入/opt/目录下，下载安装包到此目下
```
sudo wget https://github.com/linkdt-tech/DAC/releases/download/v0.10.1/dacd-0.10.1-x86_64-linux.tar.gz
```
2) 解压安装包
```
sudo tar -xvzf dacd-0.10.1-x86_64-linux.tar.gz
```
2)	进入/opt/dacd/目录，输入:
```
sudo ./dacd --conf="/opt/dacd/dacd.cfg" &
```
3) 确认dacd程序已经启动，输入:
```
ps –ef | grep dacd
```

### 2.	生成网关

1)	进入/opt/dacd/目录，生成网关地址，输入：
```
sudo ./dacd wallet_propose
```
```
返回结果如下：
{
   "id" : 1,
   "result" : {
      "account_id" : "zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD",
      "key_type" : "secp256k1",
      "master_key" : "TUN ARAB BAG BE GROW AWL FLAT WORD TACT ITEM RULE DADE",
      "master_seed" : "xnmGtEajykEqVsMpq7dmbFeyqWhzu",
      "master_seed_hex" : "DC40ED4F9BB31F82090C390316B4A942",
      "public_key" : "cBR2AD86XQ4zvVx5UsggyTFSDTq5NjWa3444iZ8omYyrrd43vVcr",
      "public_key_hex" : "03DDD167989B7747978068EF7BDA6BBBE34EF5D433B17ADB9E73932E8B0043788B",
      "status" : "success"
   }
}
保存地址（account_id）和私钥（master_seed）
```

2)	将生成的网关地址进行激活
```
使用钱包向刚生成的地址转入2个以上DAC
```
3)	申明地址为网关（即打开网关标志），输入：
```
sudo ./dacd submit xnmGtEajykEqVsMpq7dmbFeyqWhzu '{"Account":"zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD","Flags":0,"SetFlag":8,"TransactionType":"AccountSet"}'

至此，网关生成成功， 请妥善保存网关地址和私钥
```

## 3.	生成资产
1)	进入/opt/dacd/目录，生成数字资产地址，输入
```
sudo ./dacd wallet_propose
```
```
返回结果如下：
{
   "id" : 1,
   "result" : {
      "account_id" : "zE1sCr7VZFknyjQFWvvH1A3BYfY9yr59Gk",
      "key_type" : "secp256k1",
      "master_key" : "DON RUDE SOME END OINT SOB DRAG BAH CITY RUTH LILY HOOT",
      "master_seed" : "xxSuJswbuouEGCACMm7u9BArCK3ha",
      "master_seed_hex" : "35F59AEA9BB580767A76EC0888775A0F",
      "public_key" : "cBPCeXVjkdziRnp8JCkFe8ydEvNgnHVr37Fwd2tjKzrdc2hauM5x",
      "public_key_hex" : "02E12015D2AD252C7BF090AFF1742BC28302BCCD1DD53292E4FAB8785DFB293D38",
      "status" : "success"
   }
}
保存地址（account_id）和私钥（master_seed）
```

2)	将生成的数字资产地址进行激活
```
使用钱包向刚生成的地址转入2个以上DAC
```

3) 数字资产信任网关（信任网关才可进行资产转账）， 输入
```
sudo ./dacd submit xxSuJswbuouEGCACMm7u9BArCK3ha '{"Account":"z4ztM8wKEJyGcVJd759PBK6cntagrrESSQ","LimitAmount":{"currency":"USD","issuer":"zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD","value":"500000000"},"TransactionType":"TrustSet"}'

备注：
xxSuJswbuouEGCACMm7u9BArCK3ha 为资产账号私钥
zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD 为网关地址
500000000 为信任的数量， 信任多少则可发行多少
```

3) 发行数字资产到刚生成的地址上（即使用网关向地址转数字资产）， 输入：
```
sudo ./dacd submit xnmGtEajykEqVsMpq7dmbFeyqWhzu '{"Account":"zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD","Amount":{"currency":"USD","issuer":"zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD","value":"500000000"},"Destination":"zE1sCr7VZFknyjQFWvvH1A3BYfY9yr59Gk","TransactionType":"Payment"}'

备注：
xnmGtEajykEqVsMpq7dmbFeyqWhzu 为网关私钥
zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD 为网关地址， 其中Account和Issuer的值都为网关地址
USD 为发行的数字资产名称， 可自定义
50000000 为发行总量， 可自定义
zE1sCr7VZFknyjQFWvvH1A3BYfY9yr59Gk 为接收的数字资产账号地址

自此， 资产就发行到生成的数字资产账号上， 请妥善保管地址和私钥
```

3) 转移数字资产到钱包上(转账前钱包需要添加此资产）， 输入：
```
sudo ./dacd submit xxSuJswbuouEGCACMm7u9BArCK3ha '{"Account":"zE1sCr7VZFknyjQFWvvH1A3BYfY9yr59Gk","Amount":{"currency":"USD","issuer":"zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD","value":"500000000"},"Destination":"钱包地址","TransactionType":"Payment"}'

备注：
xxSuJswbuouEGCACMm7u9BArCK3ha为数字资产账号私钥
zBtDg4u4bBb16RoUkBnLfemWegtbuy8ioD为网关地址

自此数字资产发行完成， 可自由进行资产的转账
```
