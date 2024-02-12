export class Background {
  constructor(context, canvas, width, height,enemy1X,enemy1Y) {
    this.context = context;
    this.canvas = canvas;
    this.width = width*2;
    this.height = height*2;
    this.enemy1X = enemy1X;
    this.enemy1Y = enemy1Y;


    this.back = new Image();
    this.back.src = "photos/backgroung_grass.png";
  }

draw(carX, carY, enemy1X, enemy1Y) {
    const barrierLeft = this.canvas.width / 10;
    const barrierRight = this.canvas.width - this.canvas.width / 10;
    const barrierTop = this.canvas.height / 10;
    const barrierBottom = this.canvas.height - this.canvas.height / 10;

    this.shiftX = -(carX) + this.canvas.width / 10;
    this.shiftY = -(carY) + this.canvas.height / 10;

    if (carX < barrierLeft || enemy1X < barrierLeft) {
      this.shiftX = 0;
    }
    else if (carX > barrierRight || enemy1X > barrierRight) {
      this.shiftX = 0;
    }
    if (carY < barrierTop || enemy1Y < barrierTop) {
      this.shiftY = 0;
    }
    else if (carY > barrierBottom || enemy1Y > barrierBottom) {
      this.shiftY = 0;
    }
    this.context.drawImage(this.back, 4 * this.shiftX, 4 * this.shiftY, this.width, this.height);
}


  getShiftX() {
    return this.shiftX;
  }

  getShiftY() {
    return this.shiftY;
  }
}
