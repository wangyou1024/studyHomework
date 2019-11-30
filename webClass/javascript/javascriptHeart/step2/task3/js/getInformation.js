function alertInformation() {
    const myForm = document.forms["myForm"];
    const user = myForm["userName"].value;
    const password = myForm["password"].value;
    const surePassword = myForm["surePassword"].value;
    const sex = myForm["sex"].value;
    const age = myForm["age"].value;
    alert("登录名："+user+"\n密码：" + password + "\n确认密码：" + surePassword + "\n性别：" + sex + "\n年龄：" + age);
}
