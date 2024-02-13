<?php
@session_start();
$LangArray = array("sk", "en");
$DefaultLang = "sk";
if(@$_SESSION['NowLang']) {
	if(!in_array($_SESSION['NowLang'], $LangArray)) {
		$_SESSION['NowLang'] = $DefaultLang;
	}
}
else {
	$_SESSION['NowLang'] = $DefaultLang;
}
$language = addslashes($_GET['lang']);
if($language) {
	if(!in_array($language, $LangArray)) {
		$_SESSION['NowLang'] = $DefaultLang;
	}
	else {
		$_SESSION['NowLang'] = $language;
	}
}
$CurentLang = addslashes($_SESSION['NowLang']);
include_once ("lang/lang.".$CurentLang.".php");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>CHARACTERISTIC</title>
</head>

<body>
    <header class="headerhomepage"> 
        <a href="index.php"><img src="photo\logo1.svg" alt="logo" class="logo"></a>
        
        <nav> 
            <ul class="nav_panel">
              <li><a href="video.php"><?php echo $Lang['VIDEO']; ?></a></li>
              <li><a href="photo.php"><?php echo $Lang['PHOTO']; ?></a></li>
            </ul>
        </nav>
       </header>
<div class="mainphotocentr">
<img src="photo\p5.png" alt="Phone" class="mainphoto">
</div>

<div class="image">
    <figure> <img src="photo\p1.png" alt="Phone" class="block"> </figure>
    <figure> <img src="photo\p2.png" alt="Phone" class="block"> </figure>
    <figure> <img src="photo\p3.png" alt="Phone" class="block"> </figure>
    <figure> <img src="photo\p4.png" alt="Phone" class="block"> </figure>
</div>

<p class="ss-titl"><?php echo $Lang['CPU:']; ?>  <p class="ss-text"><?php echo $Lang['cpu1']; ?> </p></p> 

<p class="ss-titl"><?php echo $Lang['Operating system:']; ?><p class="ss-text"><?php echo $Lang['OP1']; ?> </p></p> 

<p class="ss-titl"><?php echo $Lang['Memory:']; ?> <p class="ss-text"><?php echo $Lang['6 GB / 128 GB, UFS2.1 memory type']; ?> </p></p> 

<p class="ss-titl"><?php echo $Lang['Screen:']; ?> <p class="ss-text"><?php echo $Lang['6.53 inches, IPS LCD, 1080 x 2340 pixels,']; ?> <br>
<?php echo $Lang['19.5:9 aspect ratio, 395 ppi pixel density, 450 nits manual brightness, 640 nits auto brightness, Corning Gorilla Glass 5 ']; ?></p></p> 

<p class="ss-titl"><?php echo $Lang['Battery:'];?> <p class="ss-text"> <?php echo $Lang['4500 mAh, fast charging'];?> </p></p> 

<p class="ss-titl"><?php echo $Lang['Main camera:'];?> <p class="ss-text"><?php echo $Lang['64 MP, f/1.9, 26mm (wide), 1/1.7, 0.8µm,PDAF 8 MP, f/2.2, 13mm (ultra wide), 1/4, 1.12µm']?>; <br>
<?php echo $Lang['f/2.4, 1/45, 1.75µm (macro camera)'];?><br>
<?php echo $Lang['f/2.4, 1/5, 1.75µm, depth sensor'];?><br>
<?php echo $Lang['recording 2160p@30fps, 1080p@30/60/120fps, 720p@960fps, gyro-EIS stabilization'];?> </p></p> 

<p class="ss-titl"><?php echo $Lang['Front camera:'];?> <p class="ss-text"><?php echo $Lang['20 MP, f/2.0, 0.9µm, 1080p@30fps video recording'];?></p></p> 

<p class="ss-titl"><?php echo $Lang['SIM card:'];?> <p class="ss-text"><?php echo $Lang['2 Nano-SIM'];?>	 </p></p> 

<p class="ss-titl"><?php echo $Lang['Network /'];?> <br><?php echo $Lang['data transfer:'];?> <p class="ss-text"><?php echo $Lang['GSM 900/1800/1900, 3G, 4G LTE, Wi-Fi 802.11 a/b/g/n/ac, 2.4 GHz + 5.0 GHz,'];?> <br>
<?php echo $Lang['Bluetooth 5.0, A2DP, LE, A-GPS, GLONASS, GALILEO, BDS, NFC , infrared port, USB 2.0 Type-C'];?>  </p></p> <br>

<p class="ss-titl"><?php echo $Lang['Sensors:'];?> <p class="ss-text"><?php echo $Lang['Fingerprint scanner (rear), accelerometer, gyroscope, proximity, compass'];?> </p></p> 

<p class="ss-titl"><?php echo $Lang[' Other:'];?><p class="ss-text"><?php echo $Lang['NFC,FM radio with a recording function,3.5 mm jack'];?> </p></p> 

<p class="ss-titl"><?php echo $Lang['Materials:'];?> <p class="ss-text"><?php echo $Lang['Corning Gorilla Glass 5'];?></p></p> 

<p class="ss-titl"><?php echo $Lang['Dimensions:'];?> <p class="ss-text"><?php echo $Lang['161.4 x 76.4 x 8.8 mm, weight 200 g'];?> </p></p>

<div id="fottermain">
<footer>
                  <section class="footerHomePage">RoboHub s.r.o Address Lichnerova 32, 903 01 Senec</section>
                  <section class="link-foot">
                  <a class="link" href="characteristic.php?lang=sk">Slovensky</a> |
                  <a class="link" href="characteristic.php?lang=en">English</a>
                  </section>
        </footer>
</div>

</body>
</html>