# 介绍视频

<video width="100%" controls>
      <source type="video/mp4" src="introduce.mp4">
</video>
[![](splash.png)](introduce.mp4)



# 实现功能

1、核心功能全部实现

2、使用EasyX库实现UI图形界面，所有UI均为自绘

3、UI页面切换平滑自然和动画效果，UI带有高亮等效果

4、实现了注册和登录功能，支持**邮箱验证码注册，在线保存用户信息**

5、登录密码使用**RSA加密**，保障安全

6、不同用户有不同权限，权限分为三个级别

7、实现了连续撤回功能，对于任意编辑均可进行撤回，最大撤回数量无限制

8、实现实现版本控制存档读档功能，支持管理存档，存档数量无限制。

9、数据支持备份，删除操作允许对比查找痕迹

10、实现树的可视化，并优化可视算法，仅对有效子叶显示，避免数据干扰

11、实现了按键点击音效，增强人机交互体验

12、使用mysql数据库实现数据**在线**持久化，支持高并发

13、使用php语言实现**前后端分离**

14、数据SSL加密传输，保障通讯安全

15、UI界面已形成较成熟框架，可拓展性高

16、前后端均使用成熟类库，可直接用于生产环境。

17、程序release版本对win 32程序加壳，避免杀软误报以及增大破解难度



> 注：PHP源码已打包到项目文件（.\php）
>
> PHP API Address: [www.wm-valley.com/cms/cms.php](http://www.wm-valley.com/cms/cms.php)
>
> 协议数字证书：ca-bundle.crt
>
> 
>
> MYSQL数据库：
>
> Address: 82.157.255.242
>
> Port: 3306
>
> Account: admin
>
> Password: 23Nypdt7GDNt4MSW
>
> DataBaseName: cms
>
> Console: [phpMyAdmin](http://82.157.255.242:888/phpmyadmin_bAnurgNjPgjJTLxe/index.php)
>
> 
>
> RSA Public Key：
>
> -----BEGIN PUBLIC KEY-----
>
> MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCAhDZFe6UuxD2V2Gjf0HSlCxSW
>
> R+92+v9NG+B3sXfjS/uzcSZiXeuyaFmTLB6QeCKA5Snou8uZyMNE3Bvdk1So1DPH
>
> HLajsHpERRNXiEVdxd60xEEM/d/uqtey1napFiTNNStIjIcKb0+8S5Sy4GOsGrsc
>
> AgRx3wYCAjF6QSqtOQIDAQAB
>
> -----END PUBLIC KEY-----
>
> 
>
> RSA Private Key：
>
> -----BEGIN RSA PRIVATE KEY-----
>
> MIICWwIBAAKBgQCAhDZFe6UuxD2V2Gjf0HSlCxSWR+92+v9NG+B3sXfjS/uzcSZi
>
> XeuyaFmTLB6QeCKA5Snou8uZyMNE3Bvdk1So1DPHHLajsHpERRNXiEVdxd60xEEM
>
> /d/uqtey1napFiTNNStIjIcKb0+8S5Sy4GOsGrscAgRx3wYCAjF6QSqtOQIDAQAB
>
> AoGAKPq/mXlbSyXNI3ZdvpxoTWZSmrb2b0CK3uoYMeJ3gZVtfaMDY9NiAEIQ6gJj
>
> /pooGmS4b9tOCUwAo/jxs74yfKctL3HCoQcBfhAyGiyblby+oJ+i4zw8Sxlzjnp7
>
> yBDZ2lRdDzLEYrab4e6UKTh6YTPNr2nI81JbIxghiA656lcCQQCCjmomitVvOpNm
>
> a3Nnkh3fEl4tRaZNorY202oXJfO2W7EJfZbJg95HUJqC6mG3o0uOcCr7izQw9N0g
>
> cBhJbO37AkEA/AALVSWEjKrWR57HTN8Z8jklkSzeiZVD5efT4ReabyeQQ4ZmoHpU
>
> woOi8e3fo+7NrvTNE8XfBkT4LWY2wHMvWwJAOT42PsX6xTU6sdqFFDFV1ZwZHOKA
>
> A2RHXoyd5J5oWFmlqxKczah7CmvGA4a+56S6mS6HOhmT/a8vUWy0yWTwhwJAZCuU
>
> VaVTOiNSiCeqa3kntCxZLYsbbq9BzSrJA2nBfrvIUb8kHlhiRuvSor5+rohnhEtV
>
> Fa4LCE/0Iv/FddyTjwJAWAUw9vXkEiUhGY9DoPlHynSaaGwpHzgDAPk9meW0AzCy
>
> WB6kxSQIQIrifhQI3aTqbOjkqFW0O9uT9zLHvVzJ0Q==
>
> -----END RSA PRIVATE KEY-----



# 遇到的问题

1、无法可视化编程，界面制作困难

2、EasyX性能差，界面动态化过高，资源占用大

3、Visual Studio对于非main源文件的更改不会重新编译，调试困难，项目移植到CLion时出现问题

4、Git无法连接，版本控制困难。无版本控制会导致回滚动辄数百行

5、PHP版本更迭快，服务器兼容性差，无法实现稳定控制，旧语法无法使用

6、各种字符串类型转换冗杂且互不兼容（string、wstring、const char * 、char * 、const wchar * 、wchar * 、LPCTSTR）

7、发现了win32 api优先级大于easyx的窗口消息（已通过控制响应范围解决）

8、前端传入的值中的“ + ”会被自动替换成空格，需要后端手动进行转换（血的教训）



注：本程序仅支持x64环境中编译与运行

​		关于php后端服务器的配置见.\php\Readme.md



