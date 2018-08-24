## 区块链网络搭建
需要至少 4 个验证节点，每个验证节点需要生成public key和seed。
### 1.	验证节点的生成
1)	将可执行程序放在目录/opt/dac/bin，将配置文件放在目录/opt/dac/etc
2)	进入/opt/dac/bin目录，输入:
```
sudo ./dacd --conf="/opt/dac/etc/dacd.cfg"
```
3)	确认dacd程序已经启动，输入ps –ef | grep dacd，看是否列出dacd进程
4)	生成validation_public_key及validation_seed, 输入:<br>
```
sudo ./dacd --conf="/opt/dac/etc/dacd.cfg"  validation_create
```
5)	返回结果如下：
```
{
   "status" : "success",
   "validation_key" : "TUCK NUDE CORD BERN LARD COCK ENDS ETC GLUM GALE CASK KEG",
   "validation_public_key" : "n9L9BaBQr3KwGuMoRWisBbqXfVoKfdJg3Nb3H1gjRSiM1arQ4vNg",
   "validation_seed" : "xxjX5VuTjQKvkTSw6EUyZnahbpgS1"
}
```
6)	分别在4个节点进行同样的操作，得到各自的validation_public_key及validation_seed

### 2.	配置文件的修改
所有需要参与共识的节点的dacd.cfg都要进行下面1,2,3,4的修改（普通节点可不用修改）：
1)	字段[ips]，添加其它三个节点的ip及端口号5123，如下例所示：
```
[ips]
139.129.99.7 5123
101.201.40.124 5123
139.224.0.105 5123
```

2)	字段[validation_seed]，添加本节点的validation_seed，如下例所示：
```
[validation_seed]
xxjX5VuTjQKvkTSw6EUyZnahbpgS1
```
3)	字段[validation_public_key]，添加本节点的validation_public_key，如下例所示：
```
[validation_public_key]
n9L9BaBQr3KwGuMoRWisBbqXfVoKfdJg3Nb3H1gjRSiM1arQ4vNg
```
4)	字段 [validators]，添加另外三个节点的validation_public_key，如下例所示：
```
[validators]
n9KdidFafxRB4izPH1tdLFpBjVboQQy7MXjC8SvLvD1wsahmGc2E
n9KdidFafxRB4izPH1tdLFpBjVboQQy7MXjC8SvLvD1wsahmGc2E
n9LrzPopoh3CUiJx7AFRaCFoy4t3RafAhyoYEeYWhkMb5R7Z19oL
```

区块数据路径的修改
5) 字段 [node_db]， 修改区块数据路径， 如下例所示
[node_db]
type=RocksDB
path=/data/test/dacd/rocksdb
open_files=2000
filter_bits=12
cache_mb=256
file_size_mb=8
file_size_mult=2

6) 字段 [database_path]， 修改区块数据路径， 如下例所示
[database_path]
/data/test/dacd/db


## 3.	架设网络 　　
1)	启动dacd程序
进入dacd应用程序目录：/opt/dac/bin，执行下面的命令
```
sudo nohup ./dacd  -q  --conf="/opt/dac/etc/dacd.cfg"&
```
每个网络节点均要执行上述命令，使dac服务在后台运行。
2)	检查是否成功<br>
进入dac应用程序目录：/opt/dac/bin，执行下面的命令
```
sudo watch ./dacd  -q  --conf="/opt/dac/etc/dacd.cfg" server_info
```
若输出结果中，字段"complete_ledgers" :类似 "1-10"，则dacd服务启动成功<br>
每个网络节点的dac服务都要求成功运行
