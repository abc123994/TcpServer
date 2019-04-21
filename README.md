# TcpServer
demo
Server簡易處理信息

<h3>流程:</h3>
<pre>
1.TcpServer listen port
2.當客端上線時會觸發 <a href="https://doc.qt.io/qt-5/qtcpserver.html#incomingConnection"
title="function">function</a> 
3.變數儲存連線客端,針對不同客端的需求作處理.
4.和客端信息的定義
5.寫入信息(先用固定的大小寫入信息長度再寫入信息)
6.信息的解讀
有個待處理空間去放置已讀取客端信息,
當收到客端信息時不一定完整,
這時候保留繼續等待下次信息讀取..
確定信息完整時允以處理,並將信息從待處理空間移除
7.處理信息 (用dispatch的方式去做)
</pre>
<h3>架構:</h3>


![struct][pic]

[pic]: https://raw.githubusercontent.com/abc123994/TcpServer/develop/images/struct.PNG "struct"
