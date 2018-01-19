#Android Studio 3.0 代理设置
-----

1. 配置shadowsock代理

使用最新的shadowsock客户端软件[shadowsocks-ng](https://github.com/shadowsocks/ShadowsocksX-NG/releases/)配置shadowsock代理。

由于shadowsock只支持sock5代理，而一些软件在mac os x上不支持sock5代理，比如Android Studio，所以虽然chrome浏览器可以访问google，但是还是无法ping通google网址。

虽然shadowsocksX-NG软件中可以设置http代理，并且，在设置后，Android Studio可以ping的通www.google.com，但是在进行gradle更新的时候，仍然出现Gradle sync failed错误。

2. 使用polipo转换协议，将全局代理转换为sock5代理



3. 配置Android Studio代理