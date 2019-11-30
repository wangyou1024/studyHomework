const allKinds = [
    {title:"美味甜甜圈",image:"../images/美味甜甜圈.png"},
    {title:"芝士蛋糕",image: "../images/泡芙.png"},
    {title:"闪电泡芙",image: "../images/卡布奇诺.png"},
    {title:"慕斯甜甜圈",image: "../images/起酥圈.png"},
    {title:"软欧圈",image: "../images/马卡龙.png"},
    {title:"麦芬圈",image: "../images/曲奇饼.png"},
    {title:"起酥圈",image: "../images/美味甜甜圈.png"},
    {title:"常规蛋糕",image: "../images/泡芙.png"},
    {title:"果汁茶饮",image: "../images/卡布奇诺.png"}];

// 加载标题
function loadKind() {
    const kinds = document.getElementById("product-kinds");
    for (let i = 0; i < allKinds.length; i++){
        let kindChar = document.createElement("div");
        kindChar.className = "kind-char";
        kindChar.innerText = allKinds[i].title;
        kinds.appendChild(kindChar);
    }
}

// 加载内容
function loadContent() {
    const mainContent = document.getElementById("product-main-content");
    for (let i = 0; i < Math.ceil(allKinds.length/3); i++){
        const lineProgram = document.createElement("div");
        lineProgram.className = "product-line-programs";
        for (let j = 0; j < 3; j++){
            const oneProgram = document.createElement("div");
            oneProgram.className = "product-one-program";
            const left = (280+69.5)*j+"px";
            oneProgram.style.left = left;
            const img = document.createElement("img");
            img.src = allKinds[i*3+j].image;
            img.style.zIndex = 2;
            oneProgram.appendChild(img);
            const introduce = document.createElement("div");
            introduce.className = "product-one-introduce";
            const title = document.createElement("div");
            title.className = "product-introduce-title";
            title.innerText = allKinds[i*3+j].title;
            introduce.appendChild(title);
            const content1 = document.createElement("div");
            content1.className = "product-introduce-content";
            content1.innerHTML = "甜甜圈，百滋百特秘制配方，纯手工制作，每一个圈都堪称经典。低糖低油，口感松软，外形精致。甜甜圈，<br>" +
                "百滋百特秘制配方，每一个圈都堪称经典。低糖低油，口感松软，外形精致···";
            introduce.appendChild(content1);
            const content2 = document.createElement("div");
            content2.className = "product-introduce-content";
            content2.innerHTML = "甜甜圈，百滋百特秘制配方，纯手工制作，每一个圈都堪称经典。低糖低油，口感松软，外形精致。甜甜圈，<br>" +
                "百滋百特秘制配方，每一个圈都堪称经典。低糖低油，口感松软，外形精致··· 甜甜圈，百滋百特秘制配方，纯手<br>工制作，每一个圈都堪称经典。低糖低油，口感松软，外形精致··· ";
            introduce.appendChild(content2);
            const content3 = document.createElement("div");
            content3.className = "product-introduce-content";
            content3.innerHTML = "甜甜圈，百滋百特秘制配方，纯手工制作，每一个圈都堪称经典。低糖低油，口感松软，外形精致···";
            introduce.appendChild(content3);
            oneProgram.appendChild(introduce);
            lineProgram.appendChild(oneProgram);
        }
        mainContent.appendChild(lineProgram);
    }
}

function action(i) {
    const titles = document.getElementsByClassName("product-main-title");
    const triangle = document.getElementsByClassName("triangle");
    for (let j = 0; j < titles.length; j++){
        titles[j].style.color = "#333333";
        triangle[j].style.opacity = 0;
    }
    titles[i].style.color = "#0d90fe";
    triangle[i].style.opacity = 1;
}

function load() {
    loadKind();
    loadContent();
    action(0)
}

load();

