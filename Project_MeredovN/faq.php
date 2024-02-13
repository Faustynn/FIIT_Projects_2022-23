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
    <title>Specifications</title>
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

       <div class="pulse-effect">
        <div class="circle"></div>
        <div class="circle"></div>
        <div class="circle"></div>
        <div class="circle"></div>
   </div>

   <div class="tabulka_blok">
   <table border="1" class="tabulka1">
    <tr class="tabulkaV">
     <th>Model:</th>
     <th>Price:</th>
    </tr>
    <tr class="tabulkaV">
     <td>4/32GB</td>
     <td>150€</td>
   </tr>
   <tr class="tabulkaV">
    <td>6/64GB</td>
    <td>210€</td>
  </tr>
  <tr class="tabulkaV">
    <td>6/128GB</td>
    <td>260€</td>
  </tr>
  </table>

  <table border="1" class="tabulka1">
    <tr class="tabulkaV">
     <th>Model:</th>
     <th>NOTE 8 PRO</th>
     <th>NOTE 8 </th>
     <th>NOTE 8T </th>
     <th>NOTE 8C </th>
    </tr>
    <tr class="tabulkaV">
     <td>Processor</td>
     <td>Helio G90T</td>
     <td>Snapdragon 665</td>
     <td>Snapdragon 665 Octa-c</td>
     <td>Snapdragon 720G</td>
   </tr>
   <tr class="tabulkaV">
    <td>GPU</td>
    <td>Mali-G76 MC4</td>
    <td>Adreno 610</td>
    <td>Adreno 610</td>
    <td>GE8320</td>
  </tr>
  <tr class="tabulkaV">
    <td>RAM</td>
    <td>16GB</td>
    <td>6GB</td>
    <td>4GB</td>
    <td>6GB</td>
  </tr>
  </table>
</div>
<hr class="hr_line">
<h2 class="main"><?php echo $Lang['Mobile ringtones:']; ?></h2>
<section class="audio">
    <audio controls><source src="audio\sound1.mp3" type="audio/mp3"></audio>
    <audio controls><source src="audio\sound2.mp3" type="audio/mp3"></audio>
    <audio controls><source src="audio\sound3.mp3" type="audio/mp3"></audio>
</section>
<hr class="hr_line">
<h2 class="main"><?php echo $Lang['Custom videos:']; ?></h2>

<div class="videoblock2">
    <video width="600px" src="video\video\videxl1.mp4" muted controls></video>
    <video width="190px" src="video\video\videxl2.mp4" muted controls></video>
</div>
    <hr class="hr_line">
    <h2 class="main"><?php echo $Lang['Custom gifs:']; ?></h2>

    <div class="videoblock2">
        <img src="video\gifs\gif2.gif" alt="gif" class="gifss">
        <img src="video\gifs\gif1.gif" alt="gif" class="gifss">
    </div>
    <hr class="hr_line">

<h2 class="main"><?php echo $Lang['Interface:']; ?></h2>
<div class="galerry_position">
    <div id="gallery">
        <img src="photo\97.png" alt="photo" tabindex="0" class="border"/>
        <img src="photo\98.png" alt="photo" tabindex="0" class="border"/>
        <img src="photo\99.png" alt="photo" tabindex="0" class="border"/>
        <img src="photo\20.png" alt="photo" tabindex="0" class="border"/>
    </div>
</div>








       
       <div id="fottermain">
        <footer>
                  <section class="footerHomePage">RoboHub s.r.o Address Lichnerova 32, 903 01 Senec</section>
                  <section class="link-foot">
                  <a class="link" href="faq.php?lang=sk">Slovensky</a> |
                  <a class="link" href="faq.php?lang=en">English</a>
                  </section>
        </footer>
    </div>
</body>
</html>