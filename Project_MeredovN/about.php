<?php
@session_start();
$LangArray = array("sk", "en");
$DefaultLang = "en";
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
    <title>ABOUT</title>
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
       
    <section class="contact">
        <h1 class="main"><?php echo $Lang['About Us']; ?></h1>
        <p><?php echo $Lang['RoboHub talks about electronic devices, technology, gadgets and accessories in simple language.']; ?><br> 
        <?php echo $Lang['The site contains short articles for a wide range of readers as well as detailed information for more embedded users.']; ?></p>

<article>
    <br>
<h1><?php echo $Lang['Contacts:']; ?></h1>
<div class="iconcontact">
<img src="photo\Phone_icon.png" alt="phoneicon" class="Picon"> <p>(+380)992233777</p>
<br>
<img src="photo\email.png" alt="emailicon" class="Eicon">       <p>robohubiz@gmail.com</p>
</div>
</article>        
<br>
<p class="autor"><?php echo $Lang['Made by Meredov Nazar FIIT STU']; ?></p>

    </section>

    <img src="photo\logo.png" alt="logo" class="logo1">
    
<div class="wrapper">
</div class="content">

        <div class="footer">                                                   
            <a href="https://www.facebook.com/FIIT.STU/"><img src="photo\facebook.png" alt="iconfb" class="fb" ></a>
            <a href="https://www.instagram.com/fiitstu/"><img src="photo\inst.png" alt="iconinst" class="inst" ></a>
            <a href="https://www.youtube.com/channel/UCrwNtLO2gYn4s3o0O_d305w"><img src="photo\yt.png" alt="iconyt" class="yt" ></a>
        </div>
</div>
</div>
<div id="fottermain">
    <footer>
              <section class="footerHomePage">RoboHub s.r.o Address Lichnerova 32, 903 01 Senec</section>
              <section class="link-foot">
              <a class="link" href="about.php?lang=sk">Slovensky</a> |
                  <a class="link" href="about.php?lang=en">English</a>
              </section>
    </footer>
</div>
</body>
</html>