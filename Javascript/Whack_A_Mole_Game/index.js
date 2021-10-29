const holes = document.querySelectorAll(".hole");
const scoreBoard = document.querySelector('.score');
const moles = document.querySelectorAll(".mole");
let prevHole;
let score;
function randTime(min,max){
    return Math.round(Math.random()*(max-min)+min);
}

function randomHole(holes){
    const idx = Math.floor(Math.random()*holes.length);
    const hole = holes[idx];
    if(hole === prevHole){
        return randomHole(holes);
    }
    prevHole = hole;
    return hole;
}

function peep(){
    const time = randTime(200,1000);
    const hole = randomHole(holes);
    // console.log(time,hole);
    hole.classList.add("up");
    setTimeout(() => {
        hole.classList.remove('up');
        if(!timeUp)peep();
    },time);
}

function startGame(){
    // console.log(scoreBoard);
    scoreBoard.textContent = 0;
    score = 0;
    timeUp = false;
    peep();
    setTimeout(()=> timeUp = true, 30000);
}
function bonk(e){
    console.log("yes");
    // if(!e.trusted)return;
    score++;
    console.log(score);
    this.classList.remove('up');
    scoreBoard.textContent = score;
}

moles.forEach(mole => mole.addEventListener("click", bonk));