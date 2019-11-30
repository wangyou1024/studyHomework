$(document).ready(function () {
    $("#username-input").bind("input propertychange",function () {
        $("#username-statue").css({
            "display": "flex",
        });
        if ($("#username-input").val().length >= 6){
            $("#username-statue").removeClass("error");
            $("#username-statue").addClass("ok");
            $("#username-img").attr({
                "src" : "../images/ok.png"
            });
            $("#username-statue-intro").text("输入正确. ");
        }
        else{
            $("#username-statue").removeClass("ok");
            $("#username-statue").addClass("error");
            $("#username-img").attr({
                "src" : "../images/error.png"
            });
            $("#username-statue-intro").text("请输入至少6位用户名. ");
        }
    });
    $("#email-input").bind("input propertychange",function () {
        $("#email-statue").css({
            "display": "flex",
        });
        if (/([a-z]|[A-Z]|[0-9])+@([a-z]|[A-Z]|[0-9])+[.]com/.test($("#email-input").val())){
            $("#email-statue").removeClass("error");
            $("#email-statue").addClass("ok");
            $("#email-img").attr({
                "src" : "../images/ok.png"
            });
            $("#email-statue-intro").text("输入正确. ");
        }
        else{
            $("#email-statue").removeClass("ok");
            $("#email-statue").addClass("error");
            $("#email-img").attr({
                "src" : "../images/error.png"
            });
            $("#email-statue-intro").text("请输入正确的E-Mail地址. ");
        }
    })
    $("#submit").click(function () {
       alert("注册成功，密码已发到你的邮箱，请查收。")
    });
    $("#space").click(function () {
        $("#username-statue").css({
            "display": "none",
        });
        $("#username-input").val("");
        $("#email-statue").css({
            "display": "none",
        });
        $("#username-input").val("");
    });
});
