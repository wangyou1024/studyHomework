let page = 0;
let editStudent = 0;

let students = [{
    number: "11503080201",
    name: "张伟",
    sex: "男",
    college: "计算机科学与工程学院",
    major: "软件工程",
    grade: "2015",
    class: "1",
    age: "21",
},
    {number: "11502020102", name: "王伟", sex: "男", college: "会计学院", major: "会计学", grade: "2015", class: "2", age: "19",},
    {
        number: "11506080403",
        name: "王芳",
        sex: "女",
        college: "理学院",
        major: "数学与应用数学",
        grade: "2015",
        class: "3",
        age: "20",
    },
    {
        number: "11503080204",
        name: "李俊",
        sex: "男",
        college: "两江人工智能学院",
        major: "软件工程",
        grade: "2015",
        class: "4",
        age: "21",
    },
    {
        number: "11502020105",
        name: "王秀英",
        sex: "女",
        college: "管理学院",
        major: "人力资源管理",
        grade: "2015",
        class: "5",
        age: "19",
    },
    {
        number: "11506080406",
        name: "李娜",
        sex: "女",
        college: "经济金融学院",
        major: "经济学",
        grade: "2015",
        class: "6",
        age: "20",
    },
    {
        number: "11503080207",
        name: "张秀英",
        sex: "女",
        college: "车辆与工程学院",
        major: "汽车服务工程",
        grade: "2015",
        class: "7",
        age: "21",
    },
    {
        number: "11502020108",
        name: "刘伟",
        sex: "男",
        college: "电气与电子工程学院",
        major: "电子信息工程",
        grade: "2015",
        class: "8",
        age: "19",
    },
    {number: "11506080409", name: "张敏", sex: "女", college: "外国语学院", major: "汉语国际教育", grade: "2015", class: "9", age: "20",},
    {
        number: "11503080210",
        name: "李静",
        sex: "女",
        college: "重庆知识产权学院",
        major: "知识产权",
        grade: "2015",
        class: "1",
        age: "21",
    },
    {number: "11502020111", name: "张丽", sex: "女", college: "机械工程学院", major: "机械电子工程", grade: "2015", class: "1", age: "19",},
    {number: "11506080412", name: "王静", sex: "男", college: "理学院", major: "信息与计算科学", grade: "2015", class: "1", age: "20",},
    {
        number: "11503080213",
        name: "王丽",
        sex: "女",
        college: "计算机科学与工程学院",
        major: "计算机科学与技术",
        grade: "2015",
        class: "3",
        age: "21",
    },
    {number: "11502020114", name: "李强", sex: "男", college: "会计学院", major: "审计学", grade: "2015", class: "4", age: "19",},
    {number: "11506080415", name: "李敏", sex: "女", college: "理学院", major: "数据科学与大数据技术", grade: "2015", class: "5", age: "20",},
    {
        number: "11503080216",
        name: "王磊",
        sex: "男",
        college: "计算机科学与工程学院",
        major: "信息管理与信息系统",
        grade: "2015",
        class: "6",
        age: "21",
    },
    {
        number: "11502020117",
        name: "李军",
        sex: "男",
        college: "经济金融学院",
        major: "国际经济与贸易",
        grade: "2015",
        class: "1",
        age: "19",
    },
    {number: "11506080418", name: "刘洋", sex: "男", college: "外国语学院", major: "商务英语", grade: "2015", class: "1", age: "20",},
    {
        number: "11503080219",
        name: "张勇",
        sex: "男",
        college: "机械学院",
        major: "测控技术与仪器",
        grade: "2015",
        class: "9",
        age: "21",
    },
    {
        number: "11502020120",
        name: "李杰",
        sex: "男",
        college: "两江人工智能学院",
        major: "大数据",
        grade: "2015",
        class: "2",
        age: "19",
    },
    {
        number: "11506080421",
        name: "王艳",
        sex: "女",
        college: "药学与生物工程学院",
        major: "生物工程",
        grade: "2015",
        class: "1",
        age: "20",
    },
    {
        number: "11503080222",
        name: "李霞",
        sex: "女",
        college: "电气与电子工程学院",
        major: "通信工程",
        grade: "2015",
        class: "2",
        age: "21",
    },
    {
        number: "11502020123",
        name: "李佳慧",
        sex: "女",
        college: "车辆与工程学院",
        major: "装甲车辆工程",
        grade: "2015",
        class: "2",
        age: "19",
    },
    {number: "11506080424", name: "陈晨", sex: "男", college: "理学院", major: "应用物理学", grade: "2015", class: "4", age: "20",},
    {
        number: "11503080225",
        name: "赵俊",
        sex: "男",
        college: "机械学院",
        major: "理论与应用力学",
        grade: "2015",
        class: "5",
        age: "21",
    },
    {number: "11502020126", name: "冯利", sex: "男", college: "材料科学与工程学院", major: "材料成型及控制工程", grade: "2015", class: "6", age: "19",},
    {number: "11506080427", name: "蒋明", sex: "男", college: "理学院", major: "新能源科学与工程", grade: "2015", class: "2", age: "20",}];

render(0);

// 取消全选
function cancelCheckAll() {
    let mainCheckbox = document.getElementById("main-checkbox");
    let checkboxs = document.getElementsByClassName("one-checkbox");
    let i = 0;
    for (i = 0; i < checkboxs.length; i++) {
        if (checkboxs[i].checked == false) {
            break
        }
    }
    if (i == checkboxs.length) {
        mainCheckbox.checked = true;
    } else {
        mainCheckbox.checked = false;
    }
}

//隔行变色
function windowLoad(z) {
    let oTab = document.getElementById("table-content");
    let oldColor = '';//用于保存原来一行的颜色
    oTab.rows[z].onmouseover = function () {
        oldColor = this.style.background;
        this.style.background = "#4998e1";
    };
    oTab.rows[z].onmouseout = function () {
        this.style.background = oldColor;//鼠标移出的时候将本行的颜色设置为原来的颜色，而原来的颜色保存在oldColor中
    };
    if ((z - 1) % 2) {
        oTab.rows[z].style.background = "#dadee1";
    } else {
        oTab.rows[z].style.background = "";
    }
}

// 清空表格
function clearTable() {
    let studentTable = document.getElementById("table-content");
    for (let i = studentTable.rows.length - 1; i >= 1; i--) {
        studentTable.deleteRow(i);
    }
}

//1表示上一页，2表示下一页，其它只可刷新当前页面
function render(direction) {
    if (direction == 1) {
        if (page == 0) {
            alert("当前是第一页");
        } else {
            page--;
            clearTable();
        }
    }
    if (direction == 2) {
        if (page < Math.floor(students.length / 10)) {
            page++;
            clearTable();
        } else {
            alert("当前是最后一页");
        }
    }
    clearTable();
    document.getElementById("main-checkbox").checked = false;
    document.getElementById("nowPage").innerText = page + 1;
    document.getElementById("allPage").innerText = students.length;
    document.getElementById("current-num").innerText = page == Math.floor(students.length / 10) ? students.length % 10 : 10;
    let studentTable = document.getElementById("table-content");
    for (let i = page * 10; i < (page + 1) * 10 && i < students.length; i++) {
        let row = studentTable.insertRow();
        row.insertCell().innerHTML = "<input type='checkbox' class='one-checkbox' onclick='cancelCheckAll()'>";
        row.insertCell().innerText = i + 1;
        row.insertCell().innerText = students[i].number;
        row.insertCell().innerText = students[i].name;
        row.insertCell().innerText = students[i].sex;
        row.insertCell().innerText = students[i].college;
        row.insertCell().innerText = students[i].major;
        row.insertCell().innerText = students[i].grade;
        row.insertCell().innerText = students[i].class;
        row.insertCell().innerText = students[i].age;
        row.insertCell().innerHTML = "<a style='color:red;cursor:pointer' onclick='view(" + i + ")'>查看</a> <a style='color:red;cursor:pointer' onclick='edit(" + i + ")'>修改</a>";
        windowLoad(i + 1 - page * 10);
    }
}

// 删除
function deleteStudent() {
    let flag = -1;
    let checkboxs = document.getElementsByClassName("one-checkbox");
    for (let i = checkboxs.length - 1; i >= 0; i--) {
        if (checkboxs[i].checked == true) {
            flag = i;
            break;
        }
    }
    if (flag != -1) {
        if (confirm("是否删除")) {
            for (let i = checkboxs.length - 1; i >= 0; i--) {
                if (checkboxs[i].checked == true) {
                    students.splice(page * 10 + i, 1);
                }
            }
        }
    }
    render(0);
}

// 全选
function checkAll() {
    let mainCheckbox = document.getElementById("main-checkbox");
    let checkboxs = document.getElementsByClassName("one-checkbox");
    for (let i = 0; i < checkboxs.length; i++) {
        checkboxs[i].checked = mainCheckbox.checked;
    }
}

// 显示弹窗
function showModel() {
    document.getElementById("gray-bg").style.display = "block";
    document.getElementById("model").style.display = "block";
}

// 关闭弹窗
function cancelModel() {
    document.getElementById("gray-bg").style.display = "none";
    document.getElementById("model").style.display = "none";
    let modelInput = document.getElementsByClassName("model-one-input");
    for (let i = 0; i < modelInput.length; i++) {
        modelInput[i].value = "";
        modelInput[i].placeholder = "";
        modelInput[i].disabled = false;
        modelInput[i].style.border = "black 1px solid";
    }

    document.getElementById("decided").style.visibility = "visible";

}

// 检查合法性
function test() {
    let flag = 1;
    const number = document.getElementById("number-input");
    const name = document.getElementById("name-input");
    const sex = document.getElementById("sex-input");
    const college = document.getElementById("college-input");
    const major = document.getElementById("major-input");
    const grade = document.getElementById("grade-input");
    const class1 = document.getElementById("class-input");
    const age = document.getElementById("age-input");

    if (!/^[0-9]{11}$/.test(number.value)) {
        number.value = "";
        number.placeholder = "格式错误，请输入11位数字";
        number.style.border = "red 1px solid";
        flag = 0;
    }

    if (!/^[\u0391-\uFFE5]+$/.test(name.value)) {
        name.value = "";
        name.placeholder = "请输入中文";
        name.style.border = "red 1px solid";
        flag = 0;
    }
    if (sex.value != "男" && sex.value != "女") {
        sex.value = "";
        sex.placeholder = "请输入正确内容";
        sex.style.border = "red 1px solid";
        flag = 0;
    }
    if (!/^[\u0391-\uFFE5]+$/.test(college.value)) {
        college.value = "";
        college.placeholder = "请输入中文";
        college.style.border = "red 1px solid";
        flag = 0;
    }
    if (!/^[\u0391-\uFFE5]+$/.test(major.value)) {
        major.value = "";
        major.placeholder = "请输入中文";
        major.style.border = "red 1px solid";
        flag = 0;
    }

    if (!/^[0-9]{4}$/.test(grade.value)) {
        grade.value = "";
        grade.placeholder = "格式错误，请输入4位数字";
        grade.style.border = "red 1px solid";
        flag = 0;
    }

    if (!/^[0-9]+$/.test(class1.value)) {
        class1.value = "";
        class1.placeholder = "格式错误，请输入数字";
        class1.style.border = "red 1px solid";
        flag = 0;
    }
    if (!/^[0-9]+$/.test(age.value)) {
        age.value = "";
        age.placeholder = "格式错误，请输入数字";
        age.style.border = "red 1px solid";
        flag = 0;
    }
    return flag == 1;

}

// 新增
function add() {
    document.getElementById("model-title").innerText = "新增学生信息";
    showModel();
}

// 保存新增到数组
function saveAdd() {
    const number = document.getElementById("number-input").value;
    const name = document.getElementById("name-input").value;
    const sex = document.getElementById("sex-input").value;
    const college = document.getElementById("college-input").value;
    const major = document.getElementById("major-input").value;
    const grade = document.getElementById("grade-input").value;
    const class1 = document.getElementById("class-input").value;
    const age = document.getElementById("age-input").value;
    students.push({
        number: number,
        name: name,
        sex: sex,
        college: college,
        major: major,
        grade: grade,
        class: class1,
        age: age
    });
    cancelModel();
    render(0);
}

// 查看
function view(i) {
    document.getElementById("model-title").innerText = "查看学生信息";
    document.getElementById("number-input").value = students[i].number;
    document.getElementById("name-input").value = students[i].name;
    document.getElementById("sex-input").value = students[i].sex;
    document.getElementById("college-input").value = students[i].college;
    document.getElementById("major-input").value = students[i].major;
    document.getElementById("grade-input").value = students[i].grade;
    document.getElementById("class-input").value = students[i].class;
    document.getElementById("age-input").value = students[i].age;
    document.getElementById("number-input").disabled = true;
    document.getElementById("name-input").disabled = true;
    document.getElementById("sex-input").disabled = true;
    document.getElementById("college-input").disabled = true;
    document.getElementById("major-input").disabled = true;
    document.getElementById("grade-input").disabled = true;
    document.getElementById("class-input").disabled = true;
    document.getElementById("age-input").disabled = true;
    document.getElementById("decided").style.visibility = "hidden";
    showModel();
}

// 修改
function edit(i) {
    document.getElementById("model-title").innerText = "修改学生信息";
    document.getElementById("number-input").value = students[i].number;
    document.getElementById("name-input").value = students[i].name;
    document.getElementById("sex-input").value = students[i].sex;
    document.getElementById("college-input").value = students[i].college;
    document.getElementById("major-input").value = students[i].major;
    document.getElementById("grade-input").value = students[i].grade;
    document.getElementById("class-input").value = students[i].class;
    document.getElementById("age-input").value = students[i].age;
    editStudent = i;
    showModel();
}

// 保存修改
function saveEdit() {
    students[editStudent].number = document.getElementById("number-input").value;
    students[editStudent].name = document.getElementById("name-input").value;
    students[editStudent].sex = document.getElementById("sex-input").value;
    students[editStudent].college = document.getElementById("college-input").value;
    students[editStudent].grade = document.getElementById("grade-input").value;
    students[editStudent].class = document.getElementById("class-input").value;
    students[editStudent].age = document.getElementById("age-input").value;
    cancelModel();
    render(0);
}

// 确定按钮
function ensure() {
    if (test()) {
        if (document.getElementById("model-title").textContent === "新增学生信息") {
            saveAdd();
        } else {
            saveEdit();
        }
    }
}
