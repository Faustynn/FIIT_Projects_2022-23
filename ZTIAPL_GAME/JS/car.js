export class Car {
  constructor(context) {
    this.context = context;


    this.images = [
      "photos/car.png",
      "photos/Skin2.png",
      "photos/skin1.png",
      "photos/skins3.png"
    ];
    this.skinChoose = 0;
    this.car = new Image();
    this.car.src = this.images[this.skinChoose];
    this.speed = 1;

    this.trail = new Image();
    this.trail.src = 'photos/TopDownCarTrail.png';
    this.path = [];

    this.smoke = new Image();
    this.smoke.src = 'photos/smoke.png';
    this.smoke.width = 40;
    this.smoke.height = 20;
    this.smoke.frameWidth = 17;
    this.smoke.frameHeight = 32;
    this.smoke.frameIndex = 0;
    this.smoke.tickCount = 0;
    this.smoke.ticksPerFrame = 2;
    this.smoke.numberOfFrames = 5;


    this.fire = new Image();
    this.fire.src = 'photos/fire.png';
    this.fire.width = 40;
    this.fire.height = 20;
    this.fire.frameWidth = 17;
    this.fire.frameHeight = 32;
    this.fire.frameIndex = 0;
    this.fire.tickCount = 0;
    this.fire.ticksPerFrame = 2;
    this.fire.numberOfFrames = 5;

    this.x = 500;
    this.y = 500;
    this.angle = 0;
    this.tempx = 0;
    this.tempy = 0;
    
    

    this.shiftPressed = false;
    this.shiftStartTime = null; 
    this.speedRestoreTime = null; 

    const canvas = document.getElementById('canvas');
    this.barrierLeft = canvas.width / 11;
    this.barrierRight = canvas.width - canvas.width / 7.5;
    this.barrierTop = canvas.height / 9;
    this.barrierBottom = canvas.height - canvas.height / 6.5;

    this.cd = null;

    const ButtonVoise = document.querySelector('.voise2');
    this.selector = false;

    ButtonVoise.addEventListener('click', () => {
      this.selector == false
      if (this.selector == true) {
        ButtonVoise.textContent = 'OFF';
        this.selector = false;
      } else {
        ButtonVoise.textContent = 'ON';
        this.selector = true;
      }
    });

    this.speedSound = new Audio('audio/speed_bust.mp3');

  }

  moveUp() {
      this.tempy = this.y;
      this.y -= 2.5 * this.speed;
      this.angle = 0;
      if (this.y < this.barrierTop) {
        this.y = this.tempy;
      }
  }
  moveDown() {
    this.tempy = this.y;
    this.y += 2.5 * this.speed;
    this.angle = 180;
    if (this.y > this.barrierBottom) {
      this.y = this.tempy;
    }
  }
  moveLeft() {
    this.tempx = this.x;
    this.x -= 2.5 * this.speed;
    this.angle = -90;
    if (this.x < this.barrierLeft) {
      this.x = this.tempx;
    }
  }
  moveRight() {
    this.tempx = this.x;
    this.x += 2.5 * this.speed;
    this.angle = 90;
    if (this.x > this.barrierRight) {
      this.x = this.tempx;
    }
  }
  
  speedBoost() {
    const boostDuration = 5000; 
    const cooldownDuration = 10000;
    const boostSpeed = 2;
    
    if (!this.shiftPressed && !this.cd) {
      this.shiftPressed = true;
      this.shiftStartTime = Date.now();
      this.speed = boostSpeed;
      this.speedRestoreTime = this.shiftStartTime + boostDuration;
  
      if (this.selector === false) {
        this.speedSound.play();
      }
  
      setTimeout(() => {
        this.speed = 1;
        this.shiftPressed = false;
        this.cd = setTimeout(() => {
          this.cd = null;
        }, cooldownDuration);
      }, boostDuration);
    }
  }

  update() {
    this.path.push([this.x, this.y]);
  
    if (this.path.length > 10) {
      this.path.shift();
    }
  }
  updateSkin() {
    this.car.src = this.images[this.skinChoose];
    
    if(this.skinChoose = 0){
      this.speed = 1;
    }else if(this.skinChoose = 1){
      this.speed = 0.8;
    }else if(this.skinChoose = 2){
      this.speed = 1.5;
    }else if(this.skinChoose = 3){
      this.speed = 2;
    }
  }

  draw() {
    if(this.speed === 1){
      this.drawSmoke();
    }else{
      this.drawFire();
    }

      for (let i = 1; i < this.path.length; i++) {
        this.context.save();
        this.context.translate(this.path[i][0], this.path[i][1]);
        this.context.rotate((this.angle * Math.PI) / 180);
        this.context.drawImage(this.trail, -this.trail.width / 2, -this.trail.height / 2);
        this.context.restore();
      }

      if (this.shiftPressed) {
        const timeLeft = Math.max(this.speedRestoreTime - Date.now(), 0);
        const barWidth = 150;
        const barHeight = 15;
        const barX = canvas.width - barWidth - 20;
        const barY = canvas.height - barHeight - 20;
        const timeFraction = timeLeft / 5000;
        const remainingBarWidth = barWidth * timeFraction;
      
        this.context.fillStyle = "#ff0000";
        this.context.fillRect(barX, barY, remainingBarWidth, barHeight);
      
        this.context.strokeStyle = "#ffffff";
        this.context.lineWidth = 2;
        this.context.strokeRect(barX, barY, barWidth, barHeight);
      }
      

    this.context.save(); 
    this.context.translate(this.x, this.y); 
    this.context.rotate((this.angle * Math.PI) / 180);
    this.context.drawImage(this.car, -this.car.width / 2, -this.car.height / 2);
    this.context.restore();
  
  }

  drawSmoke() {
  this.context.save();
  
  if(this.angle === 0){
    this.context.translate(this.x, this.y+45);
    this.context.rotate(this.angle -80);
  }
  if(this.angle === 90){   
    this.context.translate(this.x-45, this.y);
    this.context.rotate((this.angle * Math.PI));
  }
  if(this.angle === -90){  
    this.context.translate(this.x+45, this.y);
    this.context.rotate((this.angle * Math.PI));
  }
  if(this.angle === 180){
    this.context.translate(this.x, this.y-45);
    this.context.rotate(this.angle -100);
  }

  this.context.drawImage(
    this.smoke,
    this.smoke.frameIndex * this.smoke.frameWidth,
    0,
    this.smoke.frameWidth,
    this.smoke.frameHeight,
    -this.smoke.width / 2,
    -this.smoke.height / 2,
    this.smoke.width,
    this.smoke.height
  );
  this.context.restore();

  this.smoke.tickCount++;

  if (this.smoke.tickCount > this.smoke.ticksPerFrame) {
    this.smoke.tickCount = 0;
    if (this.smoke.frameIndex < this.smoke.numberOfFrames - 1) {
      this.smoke.frameIndex++;
    } else {
      this.smoke.frameIndex = 0;
    }
  }
  }
  drawFire() {
  this.context.save();
  
  if(this.angle === 0){
    this.context.translate(this.x, this.y+45);
    this.context.rotate(this.angle -80);
  }
  if(this.angle === 90){   
    this.context.translate(this.x-45, this.y);
    this.context.rotate((this.angle * Math.PI));
  }
  if(this.angle === -90){  
    this.context.translate(this.x+45, this.y);
    this.context.rotate((this.angle * Math.PI));
  }
  if(this.angle === 180){
    this.context.translate(this.x, this.y-45);
    this.context.rotate(this.angle -100);
  }

  this.context.drawImage(
    this.fire,
    this.fire.frameIndex * this.fire.frameWidth,
    0,
    this.fire.frameWidth,
    this.fire.frameHeight,
    -this.fire.width / 2,
    -this.fire.height / 2,
    this.fire.width,
    this.fire.height
  );
  this.context.restore();

  this.fire.tickCount++;

  if (this.fire.tickCount > this.fire.ticksPerFrame) {
    this.fire.tickCount = 0;
    if (this.fire.frameIndex < this.fire.numberOfFrames - 1) {
      this.fire.frameIndex++;
    } else {
      this.fire.frameIndex = 0;
    }
  }
  }

  

}


