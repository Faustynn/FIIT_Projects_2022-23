export class Boosters {
  constructor(context, canvas) {
    this.context = context;
    this.canvas = canvas;
    this.width = 21;
    this.height = 21;
    
    this.x1 = Math.random() * canvas.width;
    this.y1 = Math.random() * canvas.height;
    this.x2 = Math.random() * canvas.width;
    this.y2 = Math.random() * canvas.height;
    this.x3 = Math.random() * canvas.width;
    this.y3 = Math.random() * canvas.height;

    this.speedBonus = new Image();
    this.speedBonus.src = 'photos/bonus_speed.png';
    this.deffBonus = new Image();
    this.deffBonus.src = 'photos/bonuc_ defense.png';
    this.healBonus = new Image();
    this.healBonus.src = 'photos/bonus_heal.png';

    this.collected1 = false;
    this.collected2 = false;
    this.collected3 = false;

  }

draw(carX, carY) {
    let carRadius = 12;
    let distance1 = Math.sqrt(Math.pow(this.moveX1 - carX, 2) + Math.pow(this.moveY1 - carY, 2));
    let distance2 = Math.sqrt(Math.pow(this.moveX2 - carX, 2) + Math.pow(this.moveY2 - carY, 2));
    let distance3 = Math.sqrt(Math.pow(this.moveX3 - carX, 2) + Math.pow(this.moveY3 - carY, 2));
  
    if (distance1 < carRadius + this.width / 2 && !this.collected1) {
      this.collected1 = true;
    }
    if (this.collected1){
      this.context.drawImage(this.speedBonus, 21, 522, 66, 66);
    }

    if (distance2 < carRadius + this.width / 2 && !this.collected2) {
      this.collected2 = true;
    }
    if (this.collected2){
      this.context.drawImage(this.deffBonus, 98, 522, 66, 66);
    }

    if (distance3 < carRadius + this.width / 2 && !this.collected3) {
      this.collected3 = true;
    }
    if (this.collected3){
      this.context.drawImage(this.healBonus, 172, 522, 66, 66);
    }


        this.moveX1 = -carX + this.x1;
        this.moveY1 = -carY + this.y1;
        this.moveX2 = -carX + this.x2;
        this.moveY2 = -carY + this.y2;
        this.moveX3 = -carX + this.x3;
        this.moveY3 = -carY + this.y3;  

        if(!this.collected1){
          this.context.drawImage(this.speedBonus, this.moveX1,  this.moveY1, this.width, this.height);
        }
        if(!this.collected2){
        this.context.drawImage(this.deffBonus, this.moveX2,  this.moveY2, this.width, this.height);
        }
        if(!this.collected3){
        this.context.drawImage(this.healBonus, this.moveX3,  this.moveY3, this.width, this.height);
        }
}
  update() {

  }
}
