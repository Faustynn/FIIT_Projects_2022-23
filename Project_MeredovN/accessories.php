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
    <title>Accessories</title>
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

    <div class="product-list">

        <div class="item">
            <img src="photo\complect.png">
            <div class="product">
              <h3><?php echo $Lang['Phone complect']; ?></h3>
                <span class="price">€ 777</span>
                <a href="https://www.alza.sk/" class="button"><?php echo $Lang['BUY']; ?></a>
            </div>
          </div>
          <div class="item">
            <img src="photo\glass.png">
            <div class="product">
              <h3><?php echo $Lang['Protective glass']; ?></h3>
                <span class="price">€ 10</span>
                <a href="https://www.alza.sk/" class="button"><?php echo $Lang['BUY']; ?></a>
            </div>
          </div>
          <div class="item">
            <img src="photo\headphones.png">
            <div class="product">
              <h3><?php echo $Lang['Bluetooth Headphones']; ?></h3>
                <span class="price">€ 250</span>
                <a href="https://www.alza.sk/" class="button"><?php echo $Lang['BUY']; ?></a>
            </div>
          </div>
        </div>
              <div class="product-list">
                <div class="item">
                    <img src="photo\case.png">
                    <div class="product">
                      <h3><?php echo $Lang['Phone Case']; ?></h3>
                        <span class="price">€ 10</span>
                        <a href="https://www.alza.sk/" class="button"><?php echo $Lang['BUY']; ?></a>
                    </div>
                  </div>
                  <div class="item">
                    <img src="photo\powerpank.png">
                    <div class="product">
                      <h3><?php echo $Lang['Power Bank']; ?></h3>
                        <span class="price">€ 40</span>
                        <a href="https://www.alza.sk/" class="button"><?php echo $Lang['BUY']; ?></a>
                    </div>
                  </div>
                  <div class="item">
                    <img src="photo\sim.png">
                    <div class="product">
                      <h3><?php echo $Lang['Memory card']; ?></h3>
                        <span class="price">€ 25</span>
                        <a href="https://www.alza.sk/" class="button"><?php echo $Lang['BUY']; ?></a>
                    </div>
                  </div>
              </div>

              <div id="fottermain">
                <footer>
                          <section class="footerHomePage">RoboHub s.r.o Address Lichnerova 32, 903 01 Senec</section>
                          <section class="link-foot">
                          <a class="link" href="accessories.php?lang=sk">Slovensky</a> |
                          <a class="link" href="accessories.php?lang=en">English</a>
                          </section>
                </footer>
            </div>
</body>
</html>