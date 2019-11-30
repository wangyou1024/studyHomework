const program = [{
    title: "婚庆礼台",
    image: "../images/配送1.png",
    introduce: "百滋百特秘制配方，纯手工制作，每一个圈堪称经典；低糖低油，口感松软，外形精致。<br> 精选进口食材，不含防腐剂，纯手工制作，超级酥脆，入口即化的美妙口感。"
},
    {
        title: "会议纱龙",
        image: "../images/多拿滋食品画册1-10.png",
        introduce: "我们手牵手，用热忱架起彼此之间的友谊桥梁，用真诚交换不 同世界的美丽视野，用真心打造人脉资源最灿烂的舞台。"
    },
    {title: "庆典活动", image: "../images/庆典活动.png", introduce: "真心去体验生活中的每一度热爱，去享受欢聚的每一刻美好， 去回味昔日的每一份甜蜜。"},
    {title: "主题服务", image: "../images/学校.png", introduce: "清晨，一杯浓浓的咖啡，一块酥软的曲奇饼，立刻驱散了我们 朦胧的睡意，美好的一天就此开始。"}];

function load() {
    const service = document.getElementById("service");
    for (let i = 0; i < program.length; i++) {
        const oneProgram = document.createElement("div");
        oneProgram.className = "service-one-program";
        const title = document.createElement("div");
        title.className = "service-title";
        title.innerText = program[i].title;
        const serviceTriangle = document.createElement("div");
        serviceTriangle.className = "service-triangle";
        const image = document.createElement("img");
        image.className = "service-img";
        image.src = program[i].image;
        const introduce = document.createElement("div");
        introduce.className = "service-introduce";
        introduce.innerHTML = program[i].introduce;
        if (i % 2 == 0) {
            introduce.style.paddingLeft = "17px";
            introduce.style.paddingRight = "27px";
            oneProgram.appendChild(title);
            oneProgram.appendChild(serviceTriangle);
            oneProgram.appendChild(introduce);
            oneProgram.appendChild(image);
        } else {
            introduce.style.paddingLeft = "27px";
            introduce.style.paddingRight = "17px";
            serviceTriangle.style.transform = "rotate(180deg)";
            oneProgram.appendChild(image);
            oneProgram.appendChild(introduce);
            oneProgram.appendChild(serviceTriangle);
            oneProgram.appendChild(title);
        }
        service.appendChild(oneProgram);
    }
}

load();
