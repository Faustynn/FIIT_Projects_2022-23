import { Car } from './car.js';
import { Life } from './life.js';
import { Background } from './background.js';
import { Boosters } from './boosters.js';
import { Enemy1 } from './enemy1.js';


const canvas = document.getElementById("canvas");
const context = canvas.getContext("2d");
canvas.width = 1000;
canvas.height = 600;

let timeLeft = document.getElementById("timer").value;
let time = timeLeft;

const boosters = new Boosters(context, canvas);
const enemy1 = new Enemy1(context, canvas,time);
const back = new Background(context, canvas, canvas.width*2, canvas.height*2,enemy1.x,enemy1.y);
const life = new Life(context, 5, 5);
const car = new Car(context, life);

const gameoverImage = new Image();
gameoverImage.src = 'photos/GAME-OVER.png';
const tryagainImage = new Image();
tryagainImage.src = 'photos/Press-ENTER.png';
const gameoverImage2 = new Image();
gameoverImage2.src = 'photos/GAME-OVER2.png';
const tryagainImage2 = new Image();
tryagainImage2.src = 'photos/Press-ENTER2.png';
const startImage = new Image();
startImage.src = 'photos/Pres-SPACE.png';
const carstartImage = new Image();
carstartImage.src = 'photos/carstart.gif';


const ButtonBackVoise = document.querySelector('.voise1');
const backaudio = document.querySelector('.audio1');
backaudio.volume=0.4;
backaudio.loop = true;

const howToPlayButton = document.querySelector(".HowToPlay");
const shopButton = document.querySelector(".shop");
const leaderButton = document.querySelector(".leader");
let gameStarted = false;
let gamebut = false;
let score = 0;
let Hscore = 0;

let USEskin1 = false;
let USEskin2 = false;
let USEskin3 = false;


const ShopBuyButton1 = document.querySelector(".butS1");
const ShopBuyButton2 = document.querySelector(".butS2");
const ShopBuyButton3 = document.querySelector(".butS3");

const skin1 = document.querySelector(".butS1_1");
const skin2 = document.querySelector(".butS2_2");
const skin3 = document.querySelector(".butS3_3");

function chek(){
  const S1 = false;
  const S2 = false;
  const S3 = false;
  }

//cheat menu
document.addEventListener('keydown', function (event) {
  if(event.key === 'e') {
  life.decrease();   // kill hero
  }
  if (event.key === 'p') { 
    localStorage.removeItem('leaderboard'); //clear ldboard
  }
  if (event.key === '*') {
    score = 99999; // add  money
  }
});


  BackVoise();
  ButtonBackVoise.onclick = BackVoise;

  drawStartMenu();

  howToPlayButton.addEventListener("click", () => {
   if(gameStarted === false){
    if (gamebut === false) {
      drawHowToPlay();
      gamebut = true;
      howToPlayButton.textContent = "PLAY";
    } else {
      drawStartMenu();
      gamebut = false;
      howToPlayButton.textContent = "HOW TO PLAY";
    }
   }
  });
  shopButton.addEventListener("click", () => {
  if(gameStarted === false){
    if (gamebut === false) {
      drawShop();
      gamebut = true;
      shopButton.textContent = "BACK";

      ShopBuyButton1.style.visibility = "visible";
      ShopBuyButton2.style.visibility = "visible";
      ShopBuyButton3.style.visibility = "visible";

      if(chek.S1){
        skin1.style.visibility = "visible";
      }
      if(chek.S2){
      skin2.style.visibility = "visible";
      }
      if(chek.S3){
      skin3.style.visibility = "visible";
      }

    } else {
      drawStartMenu();
      gamebut = false;
      shopButton.textContent = "SKINS SHOP";

      ShopBuyButton1.style.visibility = "hidden";
      ShopBuyButton2.style.visibility = "hidden";
      ShopBuyButton3.style.visibility = "hidden";

      skin1.style.visibility = "hidden";
      skin2.style.visibility = "hidden";
      skin3.style.visibility = "hidden";
    }
  }
  });
  leaderButton.addEventListener("click", () => {
  if(gameStarted === false){
    if (gamebut === false) {
      drawLeader();
      gamebut = true;
      leaderButton.textContent = "BACK";
    } else {
      drawStartMenu();
      gamebut = false;
      leaderButton.textContent = "LEADER BORD:";
    }
  }
  });

  skin1.addEventListener("click", () => {
    if(gameStarted === false){
     if (USEskin1 === false) {
      USEskin1 = true;
       skin1.textContent = "ON";
       car.skinChoose = 1;
       car.updateSkin();
     } else {
      USEskin1 = false;
       skin1.textContent = "OFF";
       car.skinChoose = 0;
      car.updateSkin();
     }
    }
   });
   skin2.addEventListener("click", () => {
    if(gameStarted === false){
     if (USEskin2 === false) {
      USEskin2 = true;
       skin2.textContent = "ON";
       car.skinChoose = 2;
       car.updateSkin();
     } else {
      USEskin2 = false;
       skin2.textContent = "OFF";
       car.skinChoose = 0;
      car.updateSkin();
     }
    }
   });
   skin3.addEventListener("click", () => {
    if(gameStarted === false){
     if (USEskin3 === false) {
      USEskin3 = true;
       skin3.textContent = "ON";
       car.skinChoose = 3;
       car.updateSkin();
     } else {
      USEskin3 = false;
       skin3.textContent = "OFF";
       car.skinChoose = 0;
      car.updateSkin();
     }
    }
   });

//Start game
function startGame() { 
  gameStarted = true;
  score=score+Hscore;

    life.count = 3;
    timeLeft = document.getElementById("timer").value;
    time = timeLeft;
    let main = new Main();


let timerInterval2 = setInterval(() => {
context.clearRect(0, 0, canvas.width, canvas.height);

if (timeLeft <= 0 || life.count === 0) {
  clearInterval(timerInterval2);
  clearInterval(timerInterval);
  drawEndMenu();
  return;
}
main.update();
main.draw();

context.fillStyle = "white";
context.font = "30px Arial";
context.fillText(`Time left: ${timeLeft}`, 400, 40);
}, 1000 / 60);

let timerInterval = setInterval(() => {
  timeLeft -= 1;

  if (timeLeft <= 0 || life.count === 0) {
    gameStarted = false;
    drawEndMenu();
    Hscore=time-timeLeft;
    score = Hscore + score;
    clearInterval(timerInterval);
    return;
  }
}, 1000);
localStorage.setItem('score', score);
}

//Start Menu screen
function drawStartMenu() {
  const backgroundImage = new Image();
  backgroundImage.src = 'photos/Back_start.jfif';

  backgroundImage.onload = function() {
    context.drawImage(backgroundImage, 0, 0);
    context.drawImage(startImage, 150, 200);
    context.drawImage(carstartImage, 250, 200);
  };

  document.addEventListener('keydown', function (event) {
    if (!gameStarted && event.key === ' ') {
    life.count = 3;
    startGame();
    }
    });
}

//Game over screen
function drawEndMenu() {
  let savedScore = localStorage.getItem('score');
if (savedScore > score) {
  score = savedScore;
  localStorage.setItem('score', score);
} else {
  score = score;
}

  document.addEventListener('keydown', function (event) {
    if (event.key === 'Enter') {
      life.count = 3;
      drawStartMenu();
      gameStarted = false;
     }
    });

    const backgroundImage = new Image();
    backgroundImage.src = 'photos/back_die.jpg';
    const backgroundImage2 = new Image();
    backgroundImage2.src = 'photos/back_start2.jfif';
    if(life.count ===0){
      backgroundImage.onload = function() {
        context.drawImage(backgroundImage, 0, 0);
        context.drawImage(gameoverImage, 240, 150);
        context.drawImage(tryagainImage, 240, 250);
      };
    }
    if(life.count > 0){
      backgroundImage.onload = function() {
        context.drawImage(backgroundImage2, 0, 0);
        context.drawImage(gameoverImage2, 240, 150);
        context.drawImage(tryagainImage2, 240, 250);
      };
    }
}

//Hudba
function BackVoise() {
  if (backaudio.paused) {
    backaudio.play();
    ButtonBackVoise.textContent = 'OFF';
    ButtonBackVoise.style.backgroundImage = "url('photos/sound.png')";
  }else {
    backaudio.pause();
    ButtonBackVoise.textContent = 'ON';
    ButtonBackVoise.style.backgroundImage = "url('photos/mutesound.png')";
  }
}
    
//Howtoplay menu
function drawHowToPlay() {
  const modalX = 0;
  const modalY = 0;
  const modalWidth = 1000;
  const modalHeight = 600;


  context.fillStyle = "green";
  context.fillRect(modalX, modalY, modalWidth, modalHeight);

  context.fillStyle = "white";
  context.font = "bold 24px Verdana";
  context.textAlign = "center";
  context.fillText("How play in this game?", modalX + modalWidth / 2, modalY + 50);

  context.font = "16px Arial";
  context.textAlign = "left";
  context.fillText("⓵ To start the game, write how long you want to play the round in the box on the left.", modalX + 20, modalY + 100);
  context.fillText("⓶ Press the space bar to start the game. The bottom line is very simple. In order to win, you have to live the time you specified before", modalX + 20, modalY + 125);
  context.fillText("you started. Also, if your character dies, you start the game all over again.", modalX + 40, modalY + 150);
  context.fillText("⓷ Before the start of the next round you can spend your earned points in the skin store for the hero, see the leaderboard,", modalX + 20, modalY + 175);
  context.fillText("specify a new time that you want to live.", modalX + 40, modalY + 200);
  context.fillText("⓸ Points for victory are awarded 1 to 1, but for defeat 1 to 1/2", modalX + 20, modalY + 225);

  const image1 = new Image();
  image1.src = "photos/arrows.png";
  image1.onload = function() {
    context.drawImage(image1, modalX + 125, modalY + 350, 160, 160);
    context.fillText("Use the arrow keys on your keyboard to move your character.", modalX + 10, modalY + 520);
  };
  const image2 = new Image();
  image2.src = "photos/shift.png";
  image2.onload = function() {
    context.drawImage(image2, modalX + 400, modalY + 250, 260, 100);
    context.fillText("Use the shift button to speed up your character for 5 seconds", modalX + 300, modalY + 360);
    context.fillText("but remember the cooldown is 10 seconds.", modalX + 350, modalY + 380);
  };
  const image3 = new Image();
  image3.src = "photos/123.jpg";
  image3.onload = function() {
    context.drawImage(image3, modalX + 750, modalY + 350, 160, 160);
    context.fillText("Use buttons 1 , 2 and 3 to use your available bonuses.", modalX + 605, modalY + 525);
  };
}

//Leader Bord
function drawLeader() {

  context.fillStyle = "green";
  context.fillRect(0, 0, canvas.width, canvas.height);
  
  context.fillStyle = "white";
  context.font = "bold 36px Verdana";
  context.textAlign = "center";
  context.fillText("LeaderBord:", 500,50);
  
  let leaderboard = JSON.parse(localStorage.getItem('leaderboard')) || [];
  let playerName = document.getElementById("name").value;
  let existingPlayer = leaderboard.find(player => player.name === playerName);
  if (existingPlayer) {
  existingPlayer.score += Hscore;
  existingPlayer.date = new Date();
  } else {
  leaderboard.push({score: Hscore, date: new Date(), name: playerName});
  }
  
  leaderboard.sort((a, b) => b.score - a.score);
  leaderboard = leaderboard.slice(0, 10);
  localStorage.setItem('leaderboard', JSON.stringify(leaderboard));
  
  context.fillStyle = "white";
  context.font = "bold 22px Verdana";
  context.fillText("Date", 150, 100);
  context.fillText("Name", 500, 100);
  context.fillText("Score", 850, 100);
  
  context.fillStyle = "white";
  context.font = "18px Arial";
  for (let i = 0; i < leaderboard.length; i++) {
  context.fillText(leaderboard[i].date.toLocaleString(), 150, 130 + i * 30);
  context.fillText(leaderboard[i].name, 500, 130 + i * 30);
  context.fillText(leaderboard[i].score, 850, 130 + i * 30);
  }
}

//Shop menu
function drawShop() {
  context.fillStyle = "green";
  context.fillRect(0, 0, canvas.width, canvas.height);

  context.fillStyle = "white";
  context.font = "bold 24px Verdana";
  context.textAlign = "center";
  context.fillText("SHOP:", 500,50);

  const skins = [
    { name: 'Yellow Lightning', price: 5000, image: 'photos/skin1.png' },
    { name: 'Business class', price: 1000, image: 'photos/Skin2.png' },
    { name: 'Mint tea', price: 33333, image: 'photos/skins3.png' }
  ];

  skins.forEach((skin, index) => {
    const x = 250 + (index % 3) * 200;
    const y = 200 + Math.floor(index / 3) * 200;

    const image = new Image();
    image.src = skin.image;
    image.onload = function() {
      context.drawImage(image,x,y,54,121);
    };
    context.fillStyle = 'black';
    context.font = 'bold 16px Verdana';
    context.fillText(skin.name, x+20, y + 150);
    context.font = '24px Arial';
    context.fillText(`${skin.price} $`, x+20, y + 190);
  });


  ShopBuyButton1.addEventListener("click", () => {
    if (score >= 1000) {
      ShopBuyButton1.textContent = "Purchased";
      score -= 1000;
      car.skinChoose = 1;
      car.updateSkin();
      chek.S1 = true;
    }
  });
  
  ShopBuyButton2.addEventListener("click", () => {
    if (score >= 5000) {
      ShopBuyButton2.textContent = "Purchased";
      score -= 5000;
      car.skinChoose = 2;
      car.updateSkin();
      chek.S2 = true;
    }
  });
  
  ShopBuyButton3.addEventListener("click", () => {
    if (score >= 33333) {
      ShopBuyButton3.textContent = "Purchased";
      score -= 33333;
      car.skinChoose = 3;
      car.updateSkin();
      chek.S3 = true;
    }
  });

  
}

//funcion pre boosts
function drawBoosts(){

context.beginPath();
context.arc(55, canvas.height - 45, 35, 0, 2 * Math.PI);
context.fillStyle = 'lightgreen';
context.fill();
context.strokeStyle = "darkgreen";
context.stroke();

context.beginPath();
context.arc(130, canvas.height - 45, 35, 0, 2 * Math.PI);
context.fill();
context.stroke();

context.beginPath();
context.arc(205, canvas.height - 45, 35, 0, 2 * Math.PI);
context.fill();
context.stroke();
}

let carState = {
  up: false,
  down: false,
  left: false,
  right: false,
  boost: false
};
let enemy1State = {
  up: false,
  down: false,
  left: false,
  right: false,
  boost: false
};
document.addEventListener('keydown', function (event) {
  if (gameStarted) {
    if (event.key === 'ArrowUp') {
      carState.up = true;
    }
    if (event.key === 'ArrowDown') {
      carState.down = true;
    }
    if (event.key === 'ArrowLeft') {
      carState.left = true;
    }
    if (event.key === 'ArrowRight') {
      carState.right = true;
    }
    if (event.key === 'Shift') {
      carState.boost = true;
    }
    if (event.key === 'w') {
      enemy1State.up = true;
    }
    if (event.key === 's') {
      enemy1State.down = true;
    }
    if (event.key === 'a') {
      enemy1State.left = true;
    }
    if (event.key === 'd') {
      enemy1State.right = true;
    }
    if (event.key === 'q') {
      enemy1State.boost = true;
    }
  }
});
document.addEventListener('keyup', function (event) {
  if (gameStarted) {
    if (event.key === 'ArrowUp') {
      carState.up = false;
    }
    if (event.key === 'ArrowDown') {
      carState.down = false;
    }
    if (event.key === 'ArrowLeft') {
      carState.left = false;
    }
    if (event.key === 'ArrowRight') {
      carState.right = false;
    }
    if (event.key === 'q') {
      carState.boost = false;
    }
    if (event.key === 'w') {
      enemy1State.up = false;
    }
    if (event.key === 's') {
      enemy1State.down = false;
    }
    if (event.key === 'a') {
      enemy1State.left = false;
    }
    if (event.key === 'd') {
      enemy1State.right = false;
    }
    if (event.key === 'shift') {
      enemy1State.boost = false;
    }
  }
});
document.addEventListener('keydown', function (event) {
  if (event.key === '1') {
    if(boosters.collected1){
      boosters.collected1=false;
      car.speedBoost();
    }
  } else if (event.key === '2') {
    if(boosters.collected2){
      boosters.collected2=false;
      life.Barrier = true;
    }
  } else if (event.key === '3') {
    if(boosters.collected3){
      boosters.collected3=false;
      life.increase();
    }
  }
});

//main
class Main {
  constructor() {
    this.lives = 3;
    this.scoreCount = document.querySelector('#scorecount');
    this.observers = [];
    this.addObservers(life);
  }

  

  update() {
    if (carState.up) {
      car.moveUp();
    }
    if (carState.down) {
      car.moveDown();
    }
    if (carState.left) {
      car.moveLeft();
    }
    if (carState.right) {
      car.moveRight();
    }
    if (carState.boost) {
      car.speedBoost();
    }

    if (enemy1State.up) {
      enemy1.moveUp();
    }
    if (enemy1State.down) {
      enemy1.moveDown();
    }
    if (enemy1State.left) {
      enemy1.moveLeft();
    }
    if (enemy1State.right) {
      enemy1.moveRight();
    }
    if (enemy1State.boost) {
      enemy1.speedBoost();
    }
    if(enemy1.colize){
      car.X = 500;
      car.y = 450;
      this.notifyObservers('decrease');
      if(time>=120){
        this.notifyObservers('decrease');
      }
      enemy1.colize = false;
    }
    this.scoreCount.textContent = `Points: ${score}`;
    car.update();
    enemy1.update();
  }

  draw() {
    back.draw(car.x,car.y);
    drawBoosts();
    boosters.draw(car.x,car.y);
    enemy1.draw(car.x,car.y);
    car.draw();
    life.draw(car.x,car.y);
  }

  addObservers(observer) {
    this.observers.push(observer);
  }

  notifyObservers(event) {
    this.observers.forEach(observer => {
      observer.update(event);
    });
  }
}