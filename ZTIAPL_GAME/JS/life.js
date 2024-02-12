export class Life {
  constructor(context, x, y) {
    this.context = context;
    this.x = x;
    this.y = y;

    this.image = new Image();
    this.image2 = new Image();
    this.image.src = "photos/hurt.png";
    this.image2.src = "photos/NOhurt.png";
    this.count = 3;

    this.barr = new Image();
    this.barr.src = "photos/barrier.png";

    this.hitSound = new Audio('audio/game_hit.mp3');
    this.deathSound = new Audio('audio/die.mp3');
    this.healSound = new Audio('audio/healing.mp3');

    const ButtonVoise = document.querySelector('.voise2');
    this.selector = false;

    this.Barrier = false;

    ButtonVoise.addEventListener('click', () => {
      this.selector == false
      if (this.selector == true) {
        ButtonVoise.textContent = 'OFF';
        ButtonVoise.style.backgroundImage = "url('photos/sound.png')";
        this.selector = false;
      } else {
        ButtonVoise.textContent = 'ON';
        ButtonVoise.style.backgroundImage = "url('photos/mutesound.png')";
        this.selector = true;
      }
    });
  }

  draw(carX,carY) {
    if (this.image.complete) {
      for (let i = 0; i < this.count; i++) {
        this.context.drawImage(this.image, this.x + i * 50, this.y, 50, 50);
      }
      for (let i = this.count; i < 3; i++) {
        this.context.drawImage(this.image2,this.x + i * 50, this.y, 50, 50);
      }
    }

    if(this.Barrier){
      setTimeout(() => {
          this.context.drawImage(this.barr, carX, carY);
          this.Barrier = false;
      }, 5000);
    }
  }

  decrease() {
    if (this.count > 0 &&  !this.Barrier) {
      this.count--;
      if(this.selector == false){
        this.hitSound.play();
      }
    }
    if(this.count == 0) {
      if(this.selector == false){
        this.deathSound.play();
      }
    }   
  }

  increase() {
    if (this.count < 3) {
      this.count++;
      if(this.selector == false){
        this.healSound.play();
      }
    }  
  } 

  update(event) {
    switch (event) {
      case "decrease":
        this.decrease();
        break;
      case "increase":
        this.increase();
        break
      default: break;    
    }
  }  
}