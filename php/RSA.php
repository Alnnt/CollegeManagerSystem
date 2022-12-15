<?php
/**
 * RSA算法属于非对称加密算法,非对称加密算法需要两个秘钥:公开密钥(publickey)和私有秘钥(privatekey).公开密钥和私有秘钥是一对,如果公开密钥对数据进行加密,只有用对应的私有秘钥才能解密;如果私有秘钥对数据进行加密那么只有用对应的公开密钥才能解密.因为加密解密使用的是两个不同的秘钥,所以这种算法叫做非对称加密算法.简单的说就是公钥加密私钥解密,私钥加密公钥解密.
 * 需要给PHP打开OpenSSL模块
 * 生成公钥和私钥的链接:  http://web.chacuo.net/netrsakeypair
 * openssl_pkey_get_public //检查公钥是否可用
 * openssl_public_encrypt //公钥加密
 * openssl_pkey_get_private //检查私钥是否可用
 * openssl_private_decrypt //私钥解密
 *
 */
 
// $str = '封装测试';

//$str = json_encode([ 'a'=>1, 'b'=>2, 'f'=>6,]);
//$cdata = RSA_openssl($str);

//var_dump($cdata);
//echo "<hr>";
//$ddata = RSA_openssl($cdata,'decode');
//var_dump($ddata);
 
/**
 * RSA数据加密解密
 * @param type $data
 * @param type $type encode加密  decode解密
 */
function RSA_openssl($data, $type='decode'){
    if (empty($data)) {
        return 'data参数不能为空';
    }
    if (is_array($data)) {
        return 'data参数不能是数组形式';
    }

    $rsa_private = '-----BEGIN RSA PRIVATE KEY-----
MIICWwIBAAKBgQCAhDZFe6UuxD2V2Gjf0HSlCxSWR+92+v9NG+B3sXfjS/uzcSZi
XeuyaFmTLB6QeCKA5Snou8uZyMNE3Bvdk1So1DPHHLajsHpERRNXiEVdxd60xEEM
/d/uqtey1napFiTNNStIjIcKb0+8S5Sy4GOsGrscAgRx3wYCAjF6QSqtOQIDAQAB
AoGAKPq/mXlbSyXNI3ZdvpxoTWZSmrb2b0CK3uoYMeJ3gZVtfaMDY9NiAEIQ6gJj
/pooGmS4b9tOCUwAo/jxs74yfKctL3HCoQcBfhAyGiyblby+oJ+i4zw8Sxlzjnp7
yBDZ2lRdDzLEYrab4e6UKTh6YTPNr2nI81JbIxghiA656lcCQQCCjmomitVvOpNm
a3Nnkh3fEl4tRaZNorY202oXJfO2W7EJfZbJg95HUJqC6mG3o0uOcCr7izQw9N0g
cBhJbO37AkEA/AALVSWEjKrWR57HTN8Z8jklkSzeiZVD5efT4ReabyeQQ4ZmoHpU
woOi8e3fo+7NrvTNE8XfBkT4LWY2wHMvWwJAOT42PsX6xTU6sdqFFDFV1ZwZHOKA
A2RHXoyd5J5oWFmlqxKczah7CmvGA4a+56S6mS6HOhmT/a8vUWy0yWTwhwJAZCuU
VaVTOiNSiCeqa3kntCxZLYsbbq9BzSrJA2nBfrvIUb8kHlhiRuvSor5+rohnhEtV
Fa4LCE/0Iv/FddyTjwJAWAUw9vXkEiUhGY9DoPlHynSaaGwpHzgDAPk9meW0AzCy
WB6kxSQIQIrifhQI3aTqbOjkqFW0O9uT9zLHvVzJ0Q==
-----END RSA PRIVATE KEY-----';

    //echo $data.'<br>';
    //前端传入的字符串中"+"会被替换为空格，此处应该换回来QAQ
    $data = str_replace(" ","+",$data);

    //私钥解密
    if ($type == 'decode') {
        $private_key = openssl_pkey_get_private($rsa_private);
        if (!$private_key) {
            //return('私钥不可用');
        }
        $return_de = openssl_private_decrypt(base64_decode($data), $decrypted, $private_key);
        if (!$return_de) {
            //return('解密失败,请检查RSA秘钥');
        }
        //echo $decrypted;
        return $decrypted;
    }

}

?>