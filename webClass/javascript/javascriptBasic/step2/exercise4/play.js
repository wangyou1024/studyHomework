const days = ["星期天","星期一","星期二","星期三","星期四","星期五","星期六"];
let p = document.getElementById("time");
function exchange() {
    const time = new Date();
    const content = "今天日期是："+time.getFullYear()+"年"+ (time.getMonth()+1) + "月"
        + time.getDate() + "日 " + days[time.getDay()] + " 现在的时间是：" + time.getHours()+"时"
        + time.getMinutes() + "分" + time.getSeconds() + "秒";
    p.innerText = content;
}
let change = setInterval(exchange,1000);
