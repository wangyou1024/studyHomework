const imageSource = ["../images/thumb.png","../images/thumb1.png","../images/thumb2.png","../images/thumb3.png","../images/thumb4.png"];
let marketCurrent = 0;
let figure = 1;     //用于监控鼠标位置
function showMarket() {
    const slide = document.getElementById("market-slide");
    slide.style.display = "flex";
}
function cancel() {
    const slide = document.getElementById("market-slide");
    slide.style.display = "none";
    document.getElementById("market-img").src = imageSource[marketCurrent];
    figure = 1;
}
function next() {
    marketCurrent = (marketCurrent+1)%imageSource.length;
    const image = document.getElementById("market-slide-content");
    image.src = imageSource[marketCurrent];
    const information = document.getElementById("img-information");
    information.innerText = marketCurrent+1 + "/5";
}
function last() {
    marketCurrent = (marketCurrent-1+imageSource.length)%imageSource.length;
    const image = document.getElementById("market-slide-content");
    image.src = imageSource[marketCurrent];
    const information = document.getElementById("img-information");
    information.innerText = marketCurrent+1 + "/5";
}

function out() {
    figure = 0;
}
function enter() {
    figure = 1;
}

function controlCancel() {
    if(figure == 0){
        cancel();
    }
}
