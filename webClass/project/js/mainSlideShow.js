let photos = ["../images/甜甜圈.png", "../images/green.png", "../images/orange.png"];
let current = 0;
let leftChange;
let rightChange;
let atChange;
let show=0;
let opacity = [0.001,0.001,0.001,0.001,0.001,0.001,0.0001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001];

// 完成内容加载
function addDiv(first) {
    let sliderImg = document.getElementById("slider-img");
    let backImage = "<img style='width:100%; top: 0;position: absolute' id='back-image' src='" + first + "'/>";
    let change = "";
    for (let i = 0; i < 16; i++) {
        const oneSide = "<div class='one-side' style='width: 85.375px;height: " +
            "649px;opacity: 1;overflow: hidden;top: 0;position: absolute;left: " + (i * 85.375) + "px'>" +
            "<img class='one-img' src='" + first + "' style='position: absolute;width: 1366px;" +
            "height:649px;display: block !important;top: 0;left: " +
            (-(i * 85.375)) + "px'/>" +
            "</div>";
        change += oneSide;
    }
    const leftAndRight = "<img src='../images/left.png' id='left' style='position: absolute;left:11px;top:275px' onclick='left()'>" +
        "<img src='../images/right.png' id='right' style='position: absolute;left:1299px;top:275px' onclick='right()'>";
    const all = backImage + change + leftAndRight;
    sliderImg.innerHTML = all;

}

function showLeftRight() {
    document.getElementById("left").style.display = "block";
    document.getElementById("right").style.display = "block";
}

function hiddenLeftRight() {
    document.getElementById("left").style.display = "none";
    document.getElementById("right").style.display = "none";
}

function loadSlideShow() {
    addDiv(photos[0]);
    hiddenLeftRight();
    document.getElementById("slider-img").onmouseover = showLeftRight;
    document.getElementById("slider-img").onmouseout = hiddenLeftRight;
    atChange = setInterval(left,5000);

}

// 为下一张图片的轮播作准备
function preparePhoto(next) {
    const oneImg = document.getElementsByClassName("one-img");
    const oneSide = document.getElementsByClassName("one-side");
    for (let i = 0; i < opacity.length; i++){
        opacity[i] = 0;
    }
    for (let i = 0; i < oneImg.length; i++) {
        oneImg[i].src = photos[next];
        oneSide[i].style.opacity = 0;
    }
}

// 向左变动
function changeLeftPhoto() {
    clearInterval(atChange);
    let oneImg = document.getElementsByClassName("one-img");
    let oneSide = document.getElementsByClassName("one-side");
    if (oneSide[0].style.opacity >= 1) {
        clearInterval(leftChange);
        atChange = setInterval(left,5000);
        document.getElementById("back-image").src = oneImg[0].src;
    }
    for (let i = oneSide.length - 1; i >= 0; i--) {
        if ((i == oneSide.length - 1 || oneSide[i + 1].style.opacity - oneSide[i].style.opacity > 0.125 ||
            oneSide[i + 1].style.opacity >= 1) && oneSide[i].style.opacity <= 1) {
            opacity[i] += 0.004;
            oneSide[i].style.opacity = opacity[i];
        }

    }
}

function left() {
    clearInterval(leftChange);
    document.getElementById("back-image").src = photos[current];
    current = (current-1+photos.length)%photos.length;
    preparePhoto(current);
    leftChange = setInterval(changeLeftPhoto, 1);
}

// 向右变动
function changeRightPhoto() {
    clearInterval(atChange);
    let oneImg = document.getElementsByClassName("one-img");
    let oneSide = document.getElementsByClassName("one-side");
    if (oneSide[oneSide.length-1].style.opacity >= 1) {
        clearInterval(rightChange);
        atChange = setInterval(left,5000);
        document.getElementById("back-image").src = oneImg[0].src;
    }
    for (let i = 0; i < oneSide.length; i++) {
        if ((i == 0 || oneSide[i - 1].style.opacity - oneSide[i].style.opacity > 0.125 ||
            oneSide[i - 1].style.opacity >= 1) && oneSide[i].style.opacity <= 1) {
            opacity[i] += 0.004;
            oneSide[i].style.opacity = opacity[i];
        }

    }
}

function right() {
    clearInterval(rightChange);
    document.getElementById("back-image").src = photos[current];
    current = (current+1+photos.length)%photos.length;
    preparePhoto(current);
    rightChange = setInterval(changeRightPhoto, 1);
}

loadSlideShow();
