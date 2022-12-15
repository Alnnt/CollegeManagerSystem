<?php
require_once('phpMailer.class.php');
require_once('RSA.php');

$account = $_GET["account"];
$password = $_GET["password"];
$type = $_GET["type"];   //决定是注册还是登录  login - 登录  reg - 注册
$email = $_GET["email"];
$CheckCode = $_GET["CheckCode"];
//header("Content-Type: text/html;charset=utf-8");
//error_reporting(0);



if(empty($account)){echo '请输入用户名';exit();}
if(empty($password)){echo '请输入密码';exit();}
if(empty($type)){echo 'Empty Type.';exit();}


$mysqli = mysqli_connect('82.157.255.242:3306','admin','23Nypdt7GDNt4MSW','cms'); 
if(!$mysqli)print "数据库连接失败";

$sql = $mysqli->query("set name utf8");
$sql = $mysqli->query("select * from users where account=\"$account\"");
$row = $sql->fetch_assoc();


$password = RSA_openssl($password,'decode');
$password = md5($password);

if($type == "log"){        //登录
    if($password == $row['password']){
        //print "enable";
        echo $row['permission'];
    }
    else{
        echo "账号或密码错误";
    }
}

else if($type == "reg"){     //注册
    if(empty($CheckCode)){
        echo "请输入验证码";
        exit();
    }
    if(!empty($row['account'])){
        echo "该用户名已被注册";
        exit();
    }
    if(empty($email)){
        echo '请输入邮箱';
        exit();
    }
    // $sql = $mysqli->query("select * from users where email=\"$email\"");
    // $row = $sql->fetch_assoc();
    // if(!empty($row['email'])){
    //     echo "该邮箱已被注册";
    //     exit();
    // }

    $sql = $mysqli->query("select * from CheckCode where account=\"$account\"");  //查找已有验证码列表
    $row = $sql->fetch_assoc();
    if(empty($row['account'])){
        echo "请先获取验证码";
        exit();
    }

    if($CheckCode == $row['code']){
        //echo $CheckCode.'<br>'.$row['code'];
        $mysqli->query("delete from CheckCode where account='$account'");
        $mysqli->query("insert into users values(null,'$account','$password','$email','Common')");
        echo "注册成功";
    }
    else{
        echo "验证码错误";
    }

}

else if($type == "get"){
    if(empty($email)){echo 'Empty Email.';exit();}
    $sql = $mysqli->query("select * from users where email=\"$email\"");
    $row = $sql->fetch_assoc();
    if(!empty($row['email'])){
        echo "该邮箱已被注册";
        exit(0);
    }

    $sql = $mysqli->query("select * from CheckCode where account=\"$account\"");
    $row = $sql->fetch_assoc();
    //对于已在库中记录的验证码值，则忽略传入的验证码，以库中保存的验证码为准
    if(empty($row['code'])){
        $mysqli->query("insert into CheckCode values(null,'$account','$CheckCode')");
    }
    else{
        $CheckCode = $row['code'];
    }

    switch (sendmail::sendemail("alnnt@mp-gamer.com","风车谷","$email","$account","alnnt@mp-gamer.com","计算机学院部门管理系统二步验证码","您的验证码为：$CheckCode 请保管好验证码，请勿交予他人！","您的验证码为：$CheckCode")) {
        case 'e000':
            echo "请检查您的邮件";
            break;
        case 'e001':
            echo "邮箱不合法";
            break;
    }
}


mysqli_close($mysqli);
?>