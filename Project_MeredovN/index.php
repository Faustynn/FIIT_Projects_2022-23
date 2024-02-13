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
    <title>RoboHub</title>

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
   
   <aside>
    <img src="photo\10.png" alt="photo" class="phoneHP">
   </aside>

   <article>
  <div class="description"> 
    <h1>Redmi note 8 pro</h1>
    <ul>
        <li><?php echo $Lang['cam']; ?> </li>
        <br>
        <li><?php echo $Lang['proc']; ?>  </li>
        <br>
        <li><?php echo $Lang['bat']; ?>  </li>
        <br>
        <li><?php echo $Lang['nfs']; ?>  </li>
        <br>
        <li><?php echo $Lang['8W fast charge']; ?>  </li>
        <br>
        <li><?php echo $Lang['glass']; ?>  </li>
        <br>
        <li><?php echo $Lang['6.53 FHD+Dot Drop display']; ?>  </li>
        <br>
        <li><?php echo $Lang['3D curved back']; ?></li> 
    </ul>
    <br>
    <a href="https://www.alza.sk/" class="buy"><?php echo $Lang['BUY NOW']; ?></a>
  </div>
   </article>
<div id="fottermain">
        <footer>
                  <section class="footerHomePage">RoboHub s.r.o Address Lichnerova 32, 903 01 Senec</section>
                  <section class="link-foot">
                  <a class="link" href="index.php?lang=sk">Slovensky</a> |
                  <a class="link" href="index.php?lang=en">English</a>
                  </section>
        </footer>
</div>
</body>

</html>