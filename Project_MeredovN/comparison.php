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
    <title>COMPARISON</title>
</head>
<body>
    <header class="headerhomepage"> 
    <a href="index.php"><img src="photo\logo1.svg" alt="logo" class="logo"></a>
        
        <nav> 
            <ul class="nav_panel">
            <li><a href="characteristic.php"><?php echo $Lang['CHARACTERISTIC']; ?></a></li>
          <li><a href="reviews.php"><?php echo $Lang['REVIEWS']; ?></a></li>
          <li><a href="comparison.php"><?php echo $Lang['COMPARISON']; ?></a></li>
          <li><a href="accessories.php"><?php echo $Lang['ACCESSORIES']; ?></a></li>
          <li><a href="faq.php"><?php echo $Lang['Others']; ?></a></li>

            </ul>
        </nav>
        <a href="about.php" class="about"><button><?php echo $Lang['ABOUT']; ?></button></a>
       </header>

        <div class="comparison">

        <div class="leftblock">
            <h2 class="textcomp1"><?php echo $Lang['REDMI NOTE 8 PRO']; ?> </h2>
            <img src="photo\10.png" alt="phone1" class="border">
            <ul>
                <li><?php echo $Lang['Display:  IPS 6,53 (16,59 cm)   2340 × 1080']; ?></li>
                <br>
                <li><?php echo $Lang['Refresh rate 120 Hz, touch layer polling rate 240 Hz']; ?> </li>
                <br>
                <li><?php echo $Lang['Protective glass Gorilla Glass 6']; ?></li>
                <br>
                <li><?php echo $Lang['Chipset: MediaTek Helio G90T 12 nm, 8 cores (Cortex-A76/55)']; ?></li>
                <br>
                <li><?php echo $Lang['Graphics accelerator Helio G90T']; ?> </li>
                <br>
                <li><?php echo $Lang['Memory: 6 GB RAM and 128 GB file storage (UFS 3.0)']; ?></li>
                <br>
                <li><?php echo $Lang['Cameras: Rear camera 64 Mpx']; ?><br>
                <?php echo $Lang['Front camera 20 Mpx']; ?> </li>
                <br>
                <li><?php echo $Lang['Battery: 4500 mAh, support 20W fast charging']; ?></li> 
                <br>
                <li><?php echo $Lang['Communication: 4G, Bluetooth 5']; ?></li> 
                <br>
                <li><?php echo $Lang['Equipment: Fast charging, Body fingerprint reader']; ?><br>
                <?php echo $Lang['Face unlock, FM Radio, OTG']; ?></li> 
                <br>
                <li><?php echo $Lang['Sensors Digital compass (magnetic sensor)']; ?><br>
                <?php echo $Lang['Motion sensor (accelerometer, G-sensor)']; ?><br>
                <?php echo $Lang['Gyroscope, Light sensor, Proximity sensor']; ?></li> 
                <br>
                <li><?php echo $Lang['Wireless technologies WiFi, Bluetooth']; ?><br>
                <?php echo $Lang['Infraport, GPS, NFC, GLONASS, A-GPS, Galileo, BeiDou']; ?></li> 
                <br>
                <li><?php echo $Lang['OS: Android 11 with MIUI 12 skin']; ?></li> 
            </ul>


        </div>

        <div class="rightblock">
            <h2 class="textcomp2"><?php echo $Lang['POCO X3']; ?> </h2>
            <img src="photo\original-7140.jpg" alt="phone2" class="border">
            <ul>
                <li><?php echo $Lang['Display: IPS, 6.67 inches, FHD + resolution']; ?> </li>
                <br>
                <li><?php echo $Lang['Refresh rate 120 Hz, touch layer polling rate 240 Hz']; ?> </li>
                <br>
                <li><?php echo $Lang['Protective glass Gorilla Glass 6']; ?>  </li>
                <br>
                <li><?php echo $Lang['Chipset: Qualcomm Snapdragon 860, 7 nm, 8 cores (Kryo 485)']; ?><br>
                <?php echo $Lang['maximum clock frequency 2.96 GHz']; ?>  </li>
                <br>
                <li><?php echo $Lang['Graphics accelerator Adreno 640']; ?> </li>
                <br>
                <li><?php echo $Lang['Memory: 6 GB RAM and 128 GB file storage (UFS 3.1) or 8+256 GB']; ?> </li>
                <br>
                <li><?php echo $Lang['Cameras: 48MP Main Sensor, 8MP Ultra Wide, 2MP Macro,']; ?> <br>
                <?php echo $Lang['2MP Depth Sensor, 20MP Selfie Camera']; ?> </li>
                <br>
                <li><?php echo $Lang['Battery: 5160 mAh, support 33W fast charging']; ?></li> 
                <br>
                <li><?php echo $Lang['Communication: 4G, Bluetooth 5']; ?></li> 
                <br>
                <li><?php echo $Lang['Equipment: stereo speakers, 3.5 mm audio jack, NFC,']; ?><br> 
                <?php echo $Lang['microSD card slot (up to 1 TB), side fingerprint scanner, USB-C connector,']; ?></li> 
                <br>
                <li><?php echo $Lang['LiquidCool Technology 1.0 Plus liquid cooling']; ?></li> 
                <br>
                <li><?php echo $Lang['Weight: 215g (thickness 9.4mm)']; ?></li> 
                <br>
                <li><?php echo $Lang['OS: Android 11 with MIUI 12 skin']; ?></li> 
            </ul>

        </div>

        </div>

       <div id="fottermain">
        <footer>
                  <section class="footerHomePage">RoboHub s.r.o Address Lichnerova 32, 903 01 Senec</section>
                  <section class="link-foot">
                  <a class="link" href="comparison.php?lang=sk">Slovensky</a> |
                  <a class="link" href="comparison.php?lang=en">English</a>
                  </section>
        </footer>
    </div>
</body>
</html>