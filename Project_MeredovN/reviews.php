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
    <title>REVIEWS</title>
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

<div id="elements1">

       <div class="review">
        <img src="photo\jumper.png" alt="Avatar" style="width:90px">
        <p><span><?php echo $Lang['Tim Ashizhev.']; ?></span><?php echo $Lang['Professional photographer.']; ?> </p>
        <p><?php echo $Lang['I took it because of the camera, the photos are just top, night shooting is beyond praise. The phone itself is the right size for me and fits comfortably in my hand.']; ?></p>
      </div>
      
      <div class="review">
        <img src="photo\gryzz.png" alt="Avatar" style="width:90px">
        <p><span ><?php echo $Lang['Roma Griz.']; ?></span><?php echo $Lang['Velya channel manager.']; ?> </p>
        <p><?php echo $Lang['Excellent screen, top cameras, wireless charging, excellent sound, fairly compact size, excellent communication quality with the processor.']; ?></p>
      </div>
      <div class="review">
        <img src="photo\lusik.png" alt="Avatar" style="width:90px">
        <p><span><?php echo $Lang['Ilya Miyamura.']; ?></span><?php echo $Lang['Game Expert.']; ?> </p>
        <p><?php echo $Lang['The phone is awesome. I took a replacement Samsung s9.']; ?><br>
        <?php echo $Lang['After that - this space is some kind. The screen is bright, large, tenfold optical zoom, 0.6x camera, audio - all at the highest level.']; ?><br>
        <?php echo $Lang['The battery holds more than a day of active use, which is very good in our turbulent times. Well, you can recharge someone elses phone, which is also a plus.']; ?></p>
      </div>
      
      <div class="review">
        <img src="photo\velya.png" alt="Avatar" style="width:90px">
        <p><span><?php echo $Lang['Vadim Velgorsky.']; ?></span><?php echo $Lang['Youtuber/Streamer of the channel Velya.']; ?></p>
        <p><?php echo $Lang['It was a gift for my mother. The screen is large, the camera is good, the Face ID is normal. Except that the box was a little dirty, but thats my nitpicking.']; ?><br>
        <?php echo $Lang['I had to take an additional block, because only the Lightning-Type C wire is used for charging.']; ?> </p>
      </div>
</div>

<?php
$nameErr = $emailErr = "";
$name = $email = $message = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  if (empty($_POST["name"])) {
    $nameErr = "Name is required";
  } else {
    $name = test_input($_POST["name"]);
    if (!preg_match("/^[a-zA-Z-' ]*$/",$name)) {
      $nameErr = "Only letters and white space allowed";
    }
  }
  if (empty($_POST["email"])) {
    $emailErr = "Email is required";
  } else {
    $email = test_input($_POST["email"]);
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
      $emailErr = "Invalid email format";
    }
  }
  if (empty($_POST["message"])) {
    $message = "";
  } else {
    $message = test_input($_POST["message"]);
  }
}
?>

<div id="elements2">
      <form action="" method="post" class="postcard">

        <div class="form-row">
        <label ><?php echo $Lang['Your Name']; ?></label> <input  name="user" type="text">
        </div>
        <div class="form-row">
        <label><?php echo $Lang['Your Email']; ?></label> <input name="mail" type="email" >
        </div>
        <div class="form-row">
        <label><?php echo $Lang['Your Message']; ?></label><textarea name="mess" rows="5"></textarea>
        </div>
        <div class="form-row">
        <input type="submit" value="<?php echo $Lang['Send']; ?>"> 
        </div>
      </form>
</div>


<?php 
//Создать код дя чтения данных с формы и приравнивания их к переменым и позже вписывать в файл.         
function handle_post()
{
$user=$_POST['user'];
$mail=$_POST['mail'];
$mess=$_POST['mess'];

$fp = fopen('server-data\data.txt', 'a+');
fwrite($fp,"\nName:" .$user);
fwrite($fp,"\nEmail:" .$mail);
fwrite($fp,"\nMessage:" .$mess);
fwrite($fp,"\n");


fclose($fp);
}
if($_SERVER["REQUEST_METHOD"] == "POST")
{
  handle_post();
}
  ?>

       <div id="fottermain">
        <footer>
                  <section class="footerHomePage">RoboHub s.r.o Address Lichnerova 32, 903 01 Senec</section>
                  <section class="link-foot">
                  <a class="link" href="reviews.php?lang=sk">Slovensky</a> |
                  <a class="link" href="reviews.php?lang=en">English</a>
                  </section>
        </footer>
    </div>
</body>
</html>