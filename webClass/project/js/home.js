const images = ["../images/美味甜甜圈.png","../images/泡芙.png","../images/卡布奇诺.png","../images/起酥圈.png","../images/马卡龙.png","../images/曲奇饼.png"];
const titles = ["美味甜甜圈","闪电泡芙","卡布奇诺","起酥圈","马卡龙","手工曲奇饼"];
let content = document.getElementById("home-main-content");

function loadImage() {
    //每行放三个
    for (let i = 0; i < Math.floor(images.length/3); i++){
        let lineProgram = document.createElement("div");
        lineProgram.className = "home-line-programs";
        for (let j = 0; j < 3; j++){
            let oneProgram = document.createElement("div");
            oneProgram.className = "home-one-program";
            const img = document.createElement("img");
            img.src = images[i*3+j];
            const title = document.createElement("div");
            title.className = "home-program-title";
            title.innerText = titles[i*3+j];
            const square = document.createElement("div");
            square.className = "my-square1";
            title.appendChild(square);
            const introduce = document.createElement("div");
            introduce.className = "home-program-introduce";
            introduce.innerHTML= "甜甜圈，百滋百特秘制配方，纯手工制作，<br>每一个圈都堪称经典。低糖低油，口感松软，外<br>形精致···";
            oneProgram.appendChild(img);
            oneProgram.appendChild(title);
            oneProgram.appendChild(introduce);
            lineProgram.appendChild(oneProgram);
        }
        content.appendChild(lineProgram);
    }
}

loadImage();
