let subject = [["SQL SERVER","C# OOP"],["WEB FORM","HTML/CSS/JAVASCRIPT","ORACLE"],["ASP.NET MVC","LINQ"]];
const main = '<p>subject数组的长度：'+subject.length+'</p>'
document.write(main);
for(let i = 0; i < subject.length; i++){
    const first = "<p>subject数组对象的第" + i + "个元素是另一个数组。这个小数组的长度："+subject[i].length + "</p>";
    document.write(first);

    for(let j = 0; j < subject[i].length; j++){
        const second = "<p>第"+j+"个元素：" + subject[i][j] + "</p>";
        document.write(second);
    }

    document.write("<hr />");

}
