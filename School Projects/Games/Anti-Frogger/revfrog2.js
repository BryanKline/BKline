
//Bryan Kline Dalton Navalta
//Anti-Frogger
//May 2015
//CS135

var map = document.getElementById("map"); 
var ctx = map.getContext("2d");

//Menus
var diedMenu = new Image();
diedMenu.src = "images/diedMenu.png";
var pauseImage = new Image();
pauseImage.src = "images/pauseBack.png";
var winImage = new Image();
winImage.src = "images/winMenu.png";
var loseImage = new Image();
loseImage.src = "images/loseMenu.png";
var startImage = new Image();
startImage.src = "images/startMenu.png";
var level1Image = new Image();
level1Image.src = "images/level1Menu.png";
var level2Image = new Image();
level2Image.src = "images/level2Menu.png";
var level3Image = new Image();
level3Image.src = "images/level3Menu.png";

//buttons
var quitSel = new Image();
quitSel.src = "images/buttons/QuitSel.png";
var quitUn = new Image();
quitUn.src = "images/buttons/QuitUn.png";
var soundOffSel = new Image();
soundOffSel.src = "images/buttons/SoundOffSel.png";
var soundOffUn = new Image();
soundOffUn.src = "images/buttons/SoundOffUn.png";
var soundOnSel = new Image();
soundOnSel.src = "images/buttons/SoundOnSel.png";
var soundOnUn = new Image();
soundOnUn.src = "images/buttons/SoundOnUn.png";
var resumeSel = new Image();
resumeSel.src = "images/buttons/ResumeSel.png";
var resumeUn = new Image();
resumeUn.src = "images/buttons/ResumeUn.png";

//Sound initialization
var soundSquash = new Audio("audio/squash.wav");
var soundCrash = new Audio("audio/crash.wav");
var soundCop = new Audio("audio/police.wav");
var soundTransit = new Audio("audio/levelTransit.wav");
var musicGameplay = new Audio("audio/musicGame.wav");
var musicMenu = new Audio("audio/start.wav");
var musicWin = new Audio("audio/musicWin.wav");
var musicLose = new Audio("audio/lose.wav");


//The player struct.	
function Player()
{
	this.playerImage = new Image();  
	this.playerImage.src = "images/player1.jpg"; 
	this.y = 410;
	this.x = 320 - (this.playerImage.width/2);
	this.left = this.x;
	this.right = (this.x + this.playerImage.width);
	this.top = this.y;
	this.bottom = (this.y + this.playerImage.height);
	this.lives;
	this.score;	
	this.isCop = false;
}

//The Frogs struct has two images which are cycled through to simulate frog motion and one image
//for a dead frog when it gets it.
function Frogs()
{
	this.frogImage1 = new Image();
	this.frogImage2 = new Image();
	this.frogImageDead = new Image();  
	this.frogImage1.src = "images/upfrog1.jpg";
	this.frogImage2.src = "images/upfrog2.jpg"; 
	this.frogImageDead.src = "images/deadfrog.jpg"; 
	this.y;
	this.x;
	this.left = (this.x) + 40;
	this.right = this.x + this.frogImage1.width;
	this.top = this.y;
	this.bottom = this.y + this.frogImage1.height;
	this.alive = true;
	this.isCop = false;
}

//The Cars struct has four images for different types cars, these could be put in a function inside the
//struct.
function Cars()
{
	this.image = new Image();
	this.y;
	this.x;
	this.left = this.x;
	this.right;
	this.top = this.y;
	this.bottom;
	this.direction;
	this.speed;
	this.isCop = false;
}

//This is a struct that creates the top of the scene.
function TopScene()
{
	this.topImage = new Image();  
	this.topImage.src = "images/TopScene.jpg"; 
	this.topImage2 = new Image();  
	this.topImage2.src = "images/TopScene2.jpg"; 
	this.topImage3 = new Image();  
	this.topImage3.src = "images/TopScene3.jpg"; 
	this.x = 0;
	this.y = 0;		
}

//This is a struct that creates the median.	
function MedianScene()
{
	this.medianImage = new Image();  
	this.medianImage.src = "images/MedianScene.jpg"; 
	this.medianImage2 = new Image();  
	this.medianImage2.src = "images/MedianScene2.jpg"; 
	this.medianImage3 = new Image();  
	this.medianImage3.src = "images/MedianScene3.jpg"; 
	this.x = 0;
	this.y = 275;
	this.left = this.x;
	this.right = (this.x + this.medianImage.width);
	this.top = this.y;
	this.bottom = (this.y + this.medianImage.height);
	this.isCop = false;
}

//This is a struct that creates the bottom of the scene.
function BottomScene()
{
	this.bottomImage = new Image();  
	this.bottomImage.src = "images/BottomScene.jpg"; 
	this.bottomImage2 = new Image(); 
	this.bottomImage2.src = "images/BottomScene2.jpg"; 
	this.bottomImage3 = new Image(); 
	this.bottomImage3.src = "images/BottomScene3.jpg"; 
	this.x = 0;
	this.y = 450;		
}

//Objects of the above struct types are created here.
var SceneTop = new TopScene();
var SceneMedian = new MedianScene();
var SceneBottom = new BottomScene();
var frogProbability = 40;
var carProbability = 40;
var copProbability = 0;
var carSpeed = 7.5;

//in objectArray, 0 = player, 1 = frog, 2 = cars
//These lines initialize the array and its subarrays:
var objectArray = [];
for (var i = 0; i < 3; i++) 
{
	objectArray[i] = [];
}
objectArray[0][0] = new Player();

//Variables that are used globally, scrollSpeed changes the speed of the scenery scrolling.	
var pauseSelection = 0;
var soundOn = true;
var pause = false;
var dt = 1000/30.0;
var scrollSpeed = 0.4;
var horizontal = 0;
var vertical = 0;
var level = 1;
var e;
var carCountDifficulty = 60;
var carCount = 60;
var frogCount = 20;
var frogCountDifficulty = 20;
var musicFlag = 0;
var startFlag = true;
var transitTimer = 90;
var levelTransit = false;
var endFlag = false;
var deathFlag = false;
var loseSoundPlayed = false;
winFlag = false;

//Image initialization
semiLeft = new Image();  
semiLeft.src = "images/leftsemi1.jpg"; 
carLeft = new Image();  
carLeft.src = "images/leftcar1.jpg"; 
carRight1 = new Image();  
carRight1.src = "images/rightcar2.jpg"; 
carRight0 = new Image();  
carRight0.src = "images/rightcar5.jpg"; 
copRight = new Image();
copRight.src = "images/copRight.jpg" ;
copRightRed = new Image();
copRightRed.src = "images/copRightRed.jpg" ;
copRightBlue = new Image();
copRightBlue.src = "images/copRightBlue.jpg" ;
copRightBlue.addEventListener("load", gameStatusInterval());

//this function moves cars to the top of their row in the array, and randomly creates a car
function carManager() 
{
	var lengthDown = 0;
	//removes cars outside the map from the array, and consolidates cars in their array
	for (var i = 0; i < objectArray[2].length; i++) {
		if (i != objectArray[2].length - 1) {
			if (objectArray[2][i].x < -100 || objectArray[2][i].x > 640) {
				objectArray[2][i] = objectArray[2][i+1];
				objectArray[2][i+1] = 0;
				lengthDown++;		
			}
			else if ((objectArray[2][i] == 0) && i != objectArray[2].length - 1) {
				objectArray[2][i] = objectArray[2][i+1];
				objectArray[2][i+1] = 0;	
			}
		}
		else if (objectArray[2][i].x < -100 || objectArray[2][i].x > 640) {
			lengthDown++;
		}
	}
	objectArray[2].length = objectArray[2].length - lengthDown;
	//randomly creates cars using carCount variable to keep them regularly spaced
	if (carCount > 0) 
	{
		carCount--;
	}
	else if (Math.random() * 100 <= carProbability && carCount == 0) 
	{
		var carType = Math.random() * 100;
		if (carType < 26) 
		{
			var currentCarIndex = objectArray[2].length;
			objectArray[2][currentCarIndex] = new Cars();
			objectArray[2][currentCarIndex].direction = -1;
			objectArray[2][currentCarIndex].speed = carSpeed / 2;
			objectArray[2][currentCarIndex].x = 640;
			objectArray[2][currentCarIndex].y = 160;
			if (Math.random() * 100 < 50) 
			{
				objectArray[2][currentCarIndex].image = carLeft;
			}
			else 
			{
				objectArray[2][currentCarIndex].image = semiLeft;
			}
		}
		else if (carType >= 36 && carType < 46) 
		{
			var currentCarIndex = objectArray[2].length;
			objectArray[2][currentCarIndex] = new Cars();
			objectArray[2][currentCarIndex].direction = -1;
			objectArray[2][currentCarIndex].speed = carSpeed / 2;
			objectArray[2][currentCarIndex].x = 640;
			objectArray[2][currentCarIndex].y = 220;
			if (Math.random() * 100 < 50) 
			{
				objectArray[2][currentCarIndex].image = carLeft;
			}
			else 
			{
				objectArray[2][currentCarIndex].image = semiLeft;
			}
		}
		else if (carType >= 46 && carType < 69) 
		{
			var currentCarIndex = objectArray[2].length;
			objectArray[2][currentCarIndex] = new Cars();
			objectArray[2][currentCarIndex].direction = 1;
			objectArray[2][currentCarIndex].speed = carSpeed;
			objectArray[2][currentCarIndex].x = -100;
			objectArray[2][currentCarIndex].y = 400;
			
			if (Math.random() * 100 < 50) 
			{
				objectArray[2][currentCarIndex].image = carRight0;
			}
			else 
			{
				objectArray[2][currentCarIndex].image = carRight1;
			}
		} 
		else if (carType >= 69 && carType < 92) 
		{
			var currentCarIndex = objectArray[2].length;
			objectArray[2][currentCarIndex] = new Cars();
			objectArray[2][currentCarIndex].direction = 1;
			objectArray[2][currentCarIndex].speed = carSpeed;
			objectArray[2][currentCarIndex].x = -100;
			objectArray[2][currentCarIndex].y = 340;
			if (Math.random() * 100 < 50) {
				objectArray[2][currentCarIndex].image = carRight0;
			}
			else {
				objectArray[2][currentCarIndex].image = carRight1;
			}
		}
		else if (carType >= 92) 
		{
			if (level != 1)
			{
				var currentCarIndex = objectArray[2].length;
				objectArray[2][currentCarIndex] = new Cars();
				objectArray[2][currentCarIndex].direction = 1;
				objectArray[2][currentCarIndex].speed = carSpeed;
				objectArray[2][currentCarIndex].x = -100;
				if (Math.random() * 100 < 50)
				{
					objectArray[2][currentCarIndex].y = 340;
				}
				else
				{
					objectArray[2][currentCarIndex].y = 400;
				}
				objectArray[2][currentCarIndex].isCop = true;
				objectArray[2][currentCarIndex].image = copRight;	
			}
		}
		carCount = carCountDifficulty;
	}
}

function copImageChanger()
{
	setTimeout(copRed, 300);
	setTimeout(copBlue, 400);
}

function copRed()
{
	copImage = copRightRed;
}

function copBlue()
{
	copImage = copRightBlue;
}

//Functions:

//JQuery function that senses keystrokes.  
$(document).keydown(function(e) 
{
	if(e.keyCode == 37)
	{
		horizontal = -1;
	}
	else if(e.keyCode == 39)	
	{	
		horizontal = 1;
	}
	else if(e.keyCode == 38)
	{
		if (pause == true)
		{
			pauseSelection--;
		}
		else
		{
			vertical = -1;
		}
	}
	else if(e.keyCode == 40)
	{	
		if (pause == true)
		{
			pauseSelection++;
		}
		else
		{
			vertical = 1;
		}
	}
	else if(e.keyCode == 32)
	{
		//space after death
		if (deathFlag == true)
		{				
			objectArray[0][0].x = 320 - (objectArray[0][0].playerImage.width / 2);
			objectArray[0][0].y = 410;
			SceneTop.x = 0;
			SceneMedian.x = 0;
			SceneBottom.x = 0;
			deathFlag = false;
			if (objectArray[0][0].lives == 0)
			{
				endFlag = true;
			}
		}
		//space in the pause menu
		if (pause == true)
		{
			if (pauseSelection == 0)
			{
				pause = false;
			}
			else if (pauseSelection == 1)
			{
				if (soundOn == false)
				{
					soundOn = true;
				}
				else
				{
					soundOn = false;
				}
			}
			else if (pauseSelection == 2)
			{
				startFlag = true;
				musicGameplay.pause();
				musicGameplay.currentTime = 0;
				objectArray[1] = [];
				objectArray[2] = [];
				pause = false;
			}
			pauseSelection = 0;
		}
	}
	//escape
	if (e.keyCode == 27) 
	{
		if (endFlag == true)
		{
			endFlag = false;
			startFlag = true;
			pause = false;
			levelTransit = false;
		}
		else if (winFlag == true)
		{
			startFlag = true;
			musicGameplay.pause();
			musicGameplay.currentTime = 0;
			objectArray[1] = [];
			objectArray[2] = [];
			pause = false;
		}
		else if (pause == false && endFlag == false && winFlag == false && deathFlag == false && levelTransit == false && winFlag == false && startFlag == false) 
		{
			pauseSelection = 0;
			pause = true;
		}
	}
	//enter
	if (e.keyCode == 13)
	{
		if (startFlag == true)
		{
			level = 1;
			startFlag = false;
			levelTransit = true;
			pause = false;
			endFlag = false;
			deathFlag = false;
			loseSoundPlayed = false;
			objectArray[0][0].score = 0;
			objectArray[0][0].lives = 3;
			objectArray[0][0].x = 320 - (objectArray[0][0].playerImage.width / 2);
			objectArray[0][0].y = 410;
		}
	}
});

$(document).keyup(function(e) 
{
	if(e.keyCode == 37)
	{
		horizontal = 0;
	}
	if(e.keyCode == 39)
	{
		horizontal = 0;
	}
	if(e.keyCode == 38)
	{
		vertical = 0;
	}
	if(e.keyCode == 40)
	{
		vertical = 0;
	}
});

//Function that changes game state depending on keystrokes sensed.
function controls()
{
	if(horizontal == -1)
	{
		objectArray[0][0].x = (objectArray[0][0].x - 10);
	}
	if(horizontal == 1)
	{
		objectArray[0][0].x = (objectArray[0][0].x + 7.5);
	}
	if(vertical == -1)
	{
		objectArray[0][0].y = (objectArray[0][0].y - 9);
	}
	if(vertical == 1)
	{
		objectArray[0][0].y = (objectArray[0][0].y + 9);
	}	
	if(objectArray[0][0].x <= 0)
	{
		objectArray[0][0].x = 0;
	}
	if(objectArray[0][0].x >= 570)
	{
		objectArray[0][0].x = 570;
	}
	if(objectArray[0][0].y >= 410)
	{
		objectArray[0][0].y = 410;
	}
	if(objectArray[0][0].y <= 150)
	{
		objectArray[0][0].y = 150;
	}
}


//Function that scrolls the top, median and bottom structs that make up the scene.
function scroll()
{
	SceneTop.x -=  scrollSpeed * dt;
	if(SceneTop.x < -(SceneTop.topImage.width - 640))
	{
		SceneTop.x = 0;
	}

	SceneMedian.x -=  scrollSpeed * dt;
	if(SceneMedian.x < -(SceneMedian.medianImage.width + 300))
	{
		SceneMedian.x = 640;
	}

	SceneBottom.x -=  scrollSpeed * dt;
	if(SceneBottom.x < -(SceneBottom.bottomImage.width - 640))
	{
		SceneBottom.x = 0;
	}	
}


//Frog functions:

//Makes frogs
function frogMaker()
{
	if (frogCount == 0)
	{
		if (Math.random() * 100 <= frogProbability)
		{
			var newFrog = objectArray[1].length
			objectArray[1][newFrog] = new Frogs();
			objectArray[1][newFrog].alive = true;
			objectArray[1][newFrog].x = 900;
			objectArray[1][newFrog].y = 200 + (Math.random() * 240);
			frogCount = frogCountDifficulty;
		}
	}
	else
	{
		frogCount--;
	}
}

//Function that scrolls the x position of the frogs with the scenery
function frogScroll(Frog)
{
	Frog.x -= scrollSpeed * dt;
}

//Randomly cycles through the two live frog images, giving the appearance of hopping or motion.
function drawFrog(Frog)
{
	var num = (Math.random() * 100);
	if((num >= 0)&&(num < 50))
	{	
		ctx.drawImage(Frog.frogImage1, Frog.x, Frog.y);
	}
	if((num >= 50)&&(num < 100))
	{	
		ctx.drawImage(Frog.frogImage2, Frog.x, Frog.y);
	}	
}

//Changes the frog y position randomly so that the fogs don't simply fly up the
//page, but randomly kind of wait for a second or so before moving up again.
function frogHop(Frog)
{
	frogPosition(Frog);
	var num = (Math.random() * 100);
	if(((num > 10)&&(num < 20))&&(Frog.alive == true))
	{	
		Frog.y -= 15;
	}
}

//Checks to see if the Frog struct bool is alive is true, if so the above function drawFrog
//is called to make a hopping frog, if not it will remain dead.
function isFrogAlive(Frog)
{
	if(Frog.alive == true)
	{
		drawFrog(Frog);
	}	
}

//Once frogs have scrolled off the screen this function respawns the frog random positions and it
//calls the positionUpdate function to get the coordinates of their sides for collision purposes.
function frogPosition(Frog)
{
	positionUpdate(Frog, Frog.frogImage1.width, Frog.frogImage1.height);
	if(Frog.y <= 140 && Frog.alive == true)
	{
		if(objectArray[0][0].score > 0)
		{
			objectArray[0][0].score -= 10;
		}	
		Frog.alive = false;
		Frog.y = 1000;
	}
}

//Checks to see if a frog is up against the median, if so the frog just stays put in the road.
function medianAndFrog(Frog)
{
	if(collision(Frog, SceneMedian) == false)
	{
		frogHop(Frog);
	}
}

//Checks to see if there's been a collision with either a car or the player car, makes the bool
//alive false and increments the player's score, which as of yet is not working properly
//as it will continually increment if there is an intersection even if the frog is dead. 
//Also decrements the frog array as frogs leave the screen.
function frogAndCar()
{
	for (var i = 0; i < objectArray[1].length; i++) 
	{
		if (collision(objectArray[0][0], objectArray[1][i]) && (objectArray[1][i].alive == true))
		{
			objectArray[0][0].score += 10;
			objectArray[1][i].alive = false;
			if (soundOn == true)
			{
				soundSquash.play();
			}
		}
		for (var j = 0; j < objectArray[2].length; j++) 
		{
			if(collision(objectArray[2][j], objectArray[1][i]) == true)
			{
				objectArray[1][i].alive = false;
				if (soundOn == true)
				{
					soundSquash.play();
				}
			}
		}
		if (objectArray[1][i].x < -100)
		{
			for (var j = i; j < objectArray[1].length; j++) 
			{
				if (j != (objectArray[1].length - 1))
				{
					objectArray[1][j] = objectArray[1][j + 1];
				}
			}
			objectArray[1].length--;
		}
	}
}

//If the bool alive is false this draws the frog as a blood stain.
function deadFrog(Frog)
{
	if(Frog.alive == false)
	{
		ctx.drawImage(Frog.frogImageDead, Frog.x, Frog.y);
		frogHop(Frog);
	}
}

//This packages all the above frog functions into one that can be called once in update.
function setFrog(Frog)
{
	frogScroll(Frog);
	isFrogAlive(Frog);
	frogPosition(Frog);
	medianAndFrog(Frog);
	deadFrog(Frog);
}


//Car function:

//Moves the cars in either direction depending upon the way their image is facing, cars going
//the opposite direction from the player car move faster. 
function driveCar(Car)
{
	if(Car.direction == -1)
	{
		Car.x -= Car.speed * 0.2 * dt;
	}
	else if(Car.direction == 1)
	{
		Car.x += Car.speed * 0.03 * dt;
	}
}


//General functions:

function levelMenu()
{
	if(level == 1)
	{
		ctx.fillStyle = "#000000";
		ctx.fillRect(0, 0, 640, 480);
		ctx.drawImage(level1Image, 0, 0);
	}	
	else if(level == 2)
	{
		ctx.fillStyle = "#000000";
		ctx.fillRect(0, 0, 640, 480);
		ctx.drawImage(level2Image, 0, 0);
	}
	else if(level == 3)
	{
		ctx.fillStyle = "#000000";
		ctx.fillRect(0, 0, 640, 480);
		ctx.drawImage(level3Image, 0, 0);
	}
	transitTimer--;
	if (transitTimer == 0)
	{
		levelTransit = false;
	}
}

function pauseMenu()
{
	if (pauseSelection >= 3)
	{
		pauseSelection = 0;
	}
	if (pauseSelection <= -1)
	{
		pauseSelection = 2;
	}
	if (soundOn == true)
	{
		musicGameplay.play();
	}
	if (soundOn == false)
	{
		musicGameplay.pause();
	}
	ctx.fillStyle = "#000000";
	ctx.fillRect(0, 0, 640, 480);
	ctx.drawImage(pauseImage,0,0);
	if (pauseSelection == 0)
	{
		ctx.drawImage(resumeSel, 40, 100);
	}
	else
	{
		ctx.drawImage(resumeUn, 40, 100);
	}
	if (pauseSelection == 1)
	{
		if (soundOn == true)
		{
			ctx.drawImage(soundOffSel, 40, 200);
		}
		else
		{
			ctx.drawImage(soundOnSel, 40, 200);
		}
	}
	else
	{
		if (soundOn == true)
		{
			ctx.drawImage(soundOffUn, 40, 200);
		}
		else
		{
			ctx.drawImage(soundOnUn, 40, 200);
		}
	}
	if (pauseSelection == 2)
	{
		ctx.drawImage(quitSel, 40, 300);
	}
	else
	{
		ctx.drawImage(quitUn, 40, 300);
	}
}

//Checks score to see if score is in some range, and what the current level is to then resets the score, object positions 
//and the car array and changes carCountDifficulty, makes fewer frogs and increases scrollSpeed and increments level
function levelCheck()
{
	if((objectArray[0][0].score >= 10) && (level == 1))
	{	
		level = 2;
		levelTransit = true;
		transitTimer = 90;
		scrollSpeed = 0.50;
		objectArray[0][0].x = 20;
		objectArray[0][0].y = 410;
		SceneTop.x = 0;
		SceneMedian.x = 0;
		SceneBottom.x = 0;
		objectArray[2] = [];
		objectArray[1] = [];
		frogProbability = 40;
		carProbability = 40;
		carCountDifficulty = 45;
		frogCountDifficulty = 30;
	}
	else if((objectArray[0][0].score >= 20) && (level == 2))
	{
		level = 3;
		levelTransit = true;
		transitTimer = 90;
		scrollSpeed = 0.7;
		objectArray[0][0].x = 20;
		objectArray[0][0].y = 410;
		SceneTop.x = 0;
		SceneMedian.x = 0;
		SceneBottom.x = 0;
		objectArray[2] = [];
		objectArray[1] = [];
		frogProbability = 40;
		carProbability = 40;
		carSpeed = 9;
		carCountDifficulty = 30;
		frogCountDifficulty = 40;
	}
	else if((objectArray[0][0].score >= 30) && (level == 3))
	{
		if(soundOn == true)
		{
			musicWin.play();
		}	
		ctx.fillStyle = "#000000";
		ctx.fillRect(0, 0, 640, 480);
		ctx.drawImage(winImage, 0, 0);
	}
}

function winMenu()
{
	if (soundOn == true)
	{
		musicWin.play();
	}
	ctx.fillStyle = "#000000";
	ctx.fillRect(0, 0, 640, 480);
	ctx.drawImage(winImage, 0, 0);
	pause = false;
	deathFlag = false;
	endFlag = false;
	
}

function startMenu()
{
	musicGameplay.pause();
	endFlag = false;
	winFlag = false;
	deathFlag = false;
	levelTransit = false;
	ctx.fillStyle = "#000000";
	ctx.fillRect(0, 0, 640, 480);
	ctx.drawImage(startImage, 0, 0);
	transitTimer = 90;
}

//Function that takes in a struct and sets its top, bottom, left and right variables to their
//x and y values to check for collisions.
function positionUpdate(struct, width, height)
{
	struct.left = struct.x;
	struct.right = (struct.x + width);
	struct.top = struct.y;
	struct.bottom = (struct.y + height);
	
	if(struct.isCop == true)
	{
		struct.top -= 20;
		struct.bottom += 20;
		struct.left -= 20;
		struct.right += 20;
	}
}

//Function that takes in two structs and checks to see if there is overlap, this function as well as
//the above positionUpdate will probably not be necessary once a 2D array is implemented to 
//keep track of collisions.
function collision(r2, r1)
{
	return !(r2.left > r1.right ||
		r2.right < r1.left) &&
		!(r2.top > r1.bottom ||
		r2.bottom < r1.top)
	}

//Function that draws images on an interval, but first goes through the below gameStatus function
//which allows update to be interrupted.
function gameStatusInterval()	
{ 
  	setInterval(update, 1000/30.0); 
	
}

function gameEnd()
{
	if(soundOn == true && loseSoundPlayed == false)
	{
		musicGameplay.pause();
		musicGameplay.currentTime = 0;
		musicLose.play();
		loseSoundPlayed = true;
	}
	ctx.fillStyle = "#000000";
	ctx.fillRect(0, 0, 640, 480);
	ctx.drawImage(loseImage,0,0);
}

function death()
{
	musicGameplay.pause();
	ctx.fillStyle = "#000000";
	ctx.fillRect(0, 0, 640, 480);
	ctx.drawImage(diedMenu,0,0);
}

//Update function.
function update()
{
	if (pause == false && levelTransit == false && startFlag == false && endFlag == false && deathFlag == false && winFlag == false) {
		if (soundOn == true)
		{
			musicGameplay.play();
		}
		if (soundOn == false)
		{
			musicGameplay.pause();
		}
		
		ctx.fillStyle = "#000000";
		ctx.fillRect(0, 0, 640, 480);
	   
		ctx.drawImage(objectArray[0][0].playerImage, objectArray[0][0].x, objectArray[0][0].y);
		controls();

		if(level == 1)
		{
			ctx.drawImage(SceneTop.topImage, SceneTop.x, SceneTop.y);
			ctx.drawImage(SceneMedian.medianImage, SceneMedian.x, SceneMedian.y);
			ctx.drawImage(SceneBottom.bottomImage, SceneBottom.x, SceneBottom.y);
		}
		if(level == 2)
		{
			ctx.drawImage(SceneTop.topImage2, SceneTop.x, SceneTop.y);
			ctx.drawImage(SceneMedian.medianImage2, SceneMedian.x, SceneMedian.y);
			ctx.drawImage(SceneBottom.bottomImage2, SceneBottom.x, SceneBottom.y);
		}
		if(level == 3)
		{
			ctx.drawImage(SceneTop.topImage3, SceneTop.x, SceneTop.y);
			ctx.drawImage(SceneMedian.medianImage3, SceneMedian.x, SceneMedian.y);
			ctx.drawImage(SceneBottom.bottomImage3, SceneBottom.x, SceneBottom.y);
		}
		
		positionUpdate(objectArray[0][0], objectArray[0][0].playerImage.width, objectArray[0][0].playerImage.height);
		positionUpdate(SceneMedian, SceneMedian.medianImage.width, SceneMedian.medianImage.height);

		for (var i = 0; i < objectArray[2].length; i++) 
		{
			if(objectArray[2][i].isCop == true)
			{
				objectArray[2][i].image = copImage;
			}
			positionUpdate(objectArray[2][i], objectArray[2][i].image.width, objectArray[2][i].image.height);
			ctx.drawImage(objectArray[2][i].image, objectArray[2][i].x, objectArray[2][i].y);
			driveCar(objectArray[2][i]);
			if(collision(objectArray[0][0], objectArray[2][i]) == true)
			{
				if((objectArray[2][i].isCop == false)&&(soundOn == true))
				{
					soundCrash.play();
				}
				 else if((objectArray[2][i].isCop == true)&&(soundOn == true))
				{
					soundCop.play();
				}
				objectArray[0][0].lives--;
				if (level == 1)
				{
					objectArray[0][0].score = 0;
				}
				else if (level == 2)
				{
					objectArray[0][0].score = 10;
				}
				else if (level == 3)
				{
					objectArray[0][0].score = 20;
				}
				objectArray[2] = [];
				objectArray[1] = [];
				deathFlag = true;
			}
		}
		
		if(collision(objectArray[0][0], SceneMedian) == false)			
		{	
			scroll();
		}	

		if(collision(objectArray[0][0], SceneMedian) == true)
		{
			objectArray[0][0].lives--;
			objectArray[0][0].score = 0;
			objectArray[2] = [];
			if(soundOn == true)
			{
				soundCrash.play();
			}
			objectArray[1] = [];
			deathFlag = true;
		}

		ctx.font = "40px Helvetica";
		ctx.fillStyle = "white";
		ctx.fillText("Score:", 380, 50);
		ctx.fillText(objectArray[0][0].score, 500, 50);
		ctx.fillText("Lives:", 380, 100);	
		ctx.fillText(objectArray[0][0].lives, 500, 100);	
		
		frogMaker();
		for (var i = 0; i < objectArray[1].length; i++) 
		{
			setFrog(objectArray[1][i]);
		}
		frogAndCar();
		
		levelCheck();
		carManager();
		copImageChanger();
	}
	if (pause == true) {
		pauseMenu();
	}

	if (levelTransit == true)
	{
		levelMenu();
	}
	if (startFlag == true)
	{
		startMenu();
	}
	if (endFlag == true)
	{
		objectArray[0][0].x = 320 - (objectArray[0][0].playerImage.width / 2);
		objectArray[0][0].y = 410;
		gameEnd();
	}
	if (deathFlag == true)
	{
		objectArray[0][0].x = 320 - (objectArray[0][0].playerImage.width / 2);
		objectArray[0][0].y = 410;
		death();
	}
	if (winFlag == true)
	{
		winMenu();
	}
}
