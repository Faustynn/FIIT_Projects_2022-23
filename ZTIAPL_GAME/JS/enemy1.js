export class Enemy1 {
  constructor(context, canvas) {
    this.context = context;
    this.canvas = canvas;
  
    this.enemy1 = new Image();
    this.enemy1.src = "photos/enemy3.png";

    this.width = this.enemy1.width;
    this.height = this.enemy1.height;
    this.angle = 0;

    this.speed = 1;
    setInterval(() => {
      this.speed += 0.25;
    }, 3000);


    this.tempSpeed = this.speed;

    this.x = 500;
    this.y = 150;
    this.tempx = 0;
    this.tempy = 0;
    this.shiftPressed = false;
    this.shiftStartTime = null;
    this.speedRestoreTime = null;
    this.cd = null;

    this.barrierLeft = canvas.width / 11;
    this.barrierRight = canvas.width - canvas.width / 7.5;
    this.barrierTop = canvas.height / 9;
    this.barrierBottom = canvas.height - canvas.height / 6.5;
    this.colize = false;

    const ButtonVoise = document.querySelector('.voise2');
    this.selector = false;

    ButtonVoise.addEventListener('click', () => {
      this.selector == false;
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
    if (this.y < this.barrierTop-385) {
      this.y = this.tempy;
    }
}
moveDown() {
  this.tempy = this.y;
  this.y += 2.5 * this.speed;
  this.angle = 180;
  if (this.y > this.barrierBottom+60) {
    this.y = this.tempy;
  }
}
moveLeft() {
  this.tempx = this.x;
  this.x -= 2.5 * this.speed;
  this.angle = -90;
  if (this.x < this.barrierLeft-400) {
    this.x = this.tempx;
  }
}
moveRight() {
  this.tempx = this.x;
  this.x += 2.5 * this.speed;
  this.angle = 90;
  if (this.x > this.barrierRight+360) {
    this.x = this.tempx;
  }
}

  speedBoost() {
  const boostDuration = 5000; // 5 sec
  const cooldownDuration = 10000; // 10 sec
  const boostSpeed = 1+this.speed;
  
  if (!this.shiftPressed && !this.cd) {
    this.shiftPressed = true;
    this.shiftStartTime = Date.now();
    this.speed = boostSpeed;
    this.speedRestoreTime = this.shiftStartTime + boostDuration;

    if (this.selector === false) {
      this.speedSound.play();
    }

    setTimeout(() => {
      this.speed = this.tempSpeed;
      this.shiftPressed = false;
      this.cd = setTimeout(() => {
        this.cd = null;
      }, cooldownDuration);
    }, boostDuration);
  }
  }

  update() {
  }

  draw(carX,carY) {
    if (this.shiftPressed) {
      const timeLeft = Math.max(this.speedRestoreTime - Date.now(), 0);
      const barWidth = 150;
      const barHeight = 15;
      const barX = canvas.width - barWidth - 225;
      const barY = canvas.height - barHeight - 20;
      const timeFraction = timeLeft / 5000;
      const remainingBarWidth = barWidth * timeFraction;
    
      this.context.fillStyle = "yellow";
      this.context.fillRect(barX, barY, remainingBarWidth, barHeight);
    
      this.context.strokeStyle = "#ffffff";
      this.context.lineWidth = 2;
      this.context.strokeRect(barX, barY, barWidth, barHeight);
    }


    let carRadius = 12;
    let distance1 = Math.sqrt(Math.pow(this.moveX - carX, 2) + Math.pow(this.moveY - carY, 2));
    if (distance1 < carRadius + 31 && !this.colize) {
      this.colize = true;
    }
    if (this.colize){
      this.moveX = (this.x+500);
      this.moveY = (this.y+450);

      this.context.save();
      this.context.translate(this.moveX, this.moveY);
      this.context.rotate((this.angle * Math.PI) / 180);
      this.context.drawImage(this.enemy1, -this.width / 2, -this.height / 2);
      this.context.restore();

    }else{
    this.moveX = (-carX + this.x+500);
    this.moveY = (-carY + this.y+450);

      this.context.save();
      this.context.translate(this.moveX, this.moveY);
      this.context.rotate((this.angle * Math.PI) / 180);
      this.context.drawImage(this.enemy1, -this.width / 2, -this.height / 2);
      this.context.restore();
    }
  }

}     