# Reunited

 Authors: [Jason Lin](https://github.com/jjason1), [Cheng-Shun Chuang](https://github.com/ulrixon), [Aamir Khan](https://github.com/Akhan521), [Boyi Li](https://github.com/Bli181)

## Project Description
* This project is interesting to our team because it provides us with a more flexible creative space. Projects such as chess or library systems have very specific and strict rules, which would limit our creative implementations. It would leave us with little to no freedom to introduce new features into our game, so we found the idea of a text-based RPG intriguing as it is the exact opposite. RPGs can turn into any project you desire because there is an endless number of possiblities you can bring to the table. We are able to customize our story in any way we want, which is why we decided to do a text-based RPG.
* Our language of choice for this project is C++. Additionally, we'll be using Github as our version control system to manage our project throughout its lifecycle.
* Input Will Include:
  * In Menu:
    * Start New Game
    * Developer Names
    * Help
    * Quit
  * In Game (But not in battle):
    * Move to another location
    * Chat with others (NPCs)
    * Show status (Hp, Def, Etc.)
  * Start Battle
    * Once Defeated:
    * Escape/run
    * Restart combat
    * In Battle:
    * Target enemy
    * Select skill
    * Use skill
  * Between Chapters:
    * Save data
* Output Will Include:
  * In Menu:
    * Display prompts/text for our menu options
  * In Game:
    * Display area descriptions
    * Show dialog options and NPC conversations
  * In Battle:
    * Show status (Hp, atk, buffs, debuffs, etc.)
    * Show enemy lists and their statuses
    * Show abilities
    * Show NPC statuses
* Features Provided by Our Project:
  * Primary Features: 
    * Turn-based
    * Story line will be separated into chapters with savepoints at the start of each chapter
    * Enemy AI/Boss AI
    * Enemy-scaling (Enemies of different levels have different statuses.)
    * Combat system (How damage is calculated.)
    * Different character classes (Around 3 types.)
  * Potential Features:
    * Skills and/or enchanted weapons
    * NPC Followers
    * Alternative story line
    * Enemy item drops
    * Sound effects (Background music)
  
 > ## Phase II

## User Interface Specification

### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-akhan197-bli181-cchua042-jlin379/blob/master/Design_Doc/Reunited_%20User%20Interface%20Specification%20-%20Nav.%20Diagram.png)
Our users will first enter a menu phase and will be given three options to select from. If users choose to start a new game, they will start the game from the first chapter. If they choose to load a save file, they will continue from the chapter they had previously left off on. If they choose to display the developers, the developer names, contributions, and other relevant information will be displayed.

### Screen Layouts
![Screen Layouts](https://github.com/cs100/final-project-akhan197-bli181-cchua042-jlin379/blob/master/Design_Doc/Reunited_%20User%20Interface%20Specification%20-%20Screen%20Layouts.png)
This graphic illustrates the screen layouts of each of the screens that users will come across. Additionally, we included some terminal examples of what users may see in certain screens.

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-akhan197-bli181-cchua042-jlin379/blob/master/Design_Doc/Reunited_%20UML%20Diagrams.png)
We've presented two core classes, namely the "Player" and "Enemy" classes. Various other derived classes have been created, each incorporating distinct functions and/or variables. Additionally, we've integrated several supplementary classes to enhance the user's gaming experience. For example, we've added the Menu class to provide the user with a simple interface to navigate our game options. We've also added the Combat class to handle the combat throughout our game. As the graphic above illustrates, we've included the PlayerTeam and EnemyTeam classes to implement team-based gameplay. These are a few examples of the classes we've designed for our game. Refer to the graphic above for more information regarding each class.
 
 > ## Phase III

Considering the Single Responsibility Principle, we introduced a Chapter Class that would break our story down across multiple chapters, as opposed to having a single Story Class handling our entire story at once. Similarly, we introduced a SubChapter Class to further break our chapters down. This allows us to handle tasks within chapters more efficiently and effectively. It primarily separates responsibilities between chapters and subchapters, making it easier to organize and complete our tasks. 

When considering the Open-Closed Principle, we decided to create interfaces for our chapters and subchapters. For example, we designed an interface for our chapters, so that all derived chapters could implement the same interface with the same functions, albeit different definitions. This allows us to write code that is “open for extension and closed for modification”. Given the common interface, all of our derived classes can implement the same functions, and future extension of our storyline will be easier to accommodate.

After considering the Liskov-Substitution Principle, we chose to design interfaces for our chapters and subchapters. Our project makes use of these interfaces in our functions, so that any instances of their subtypes may be used, without altering the correctness of our project. This allows us to write code that is more flexible and correct, as it ensures the correctness of our program regardless of whether we use base class or subtype instances.

Considering the Interface-Segregation Principle, we wanted our design to not force the user to depend on methods or interfaces they wouldn’t need to use. To solve this consideration, we designed a Character Interface that our Player and Enemy classes would derive from. From there, our Player class would implement its own functionality, while the Enemy class would implement its specific functionality. Players would now be distinct from enemies, and each could rely on its own specific functionality. This allows us to only implement what is necessary and remove unrequired implementations. Through this change, our code is now more clear and efficient.

 > ## Final Deliverable
 
 ## Screenshots
  A link to our screenshots folder is given here:
  [Screenshots Folder Link](https://github.com/cs100/final-project-akhan197-bli181-cchua042-jlin379/blob/master/Screenshots)
 ## Installation/Usage
 Use the following instructions to run our application on terminal:
 First, clone our repo and go to the root directory.
 ```
 $ git clone https://github.com/cs100/final-project-akhan197-bli181-cchua042-jlin379.git
 $ cd final-project-akhan197-bli181-cchua042-jlin379
 ```
 Second, cmake and make the files so that you can generate the executable file for playing.
 ```
 $ cmake .
 $ make
 ```
 Finally, you can use the command below to run our game.
 ```
 $ ./bin/runMain
 ```
 ## Testing
 Our project was tested and validated using unit tests. The addition of every new feature within our program was accompanied by multiple tests. For example, our Menu class made use of ostream and istream objects to validate our inputs and outputs. Additionally, we designed our tests to cover all of our code. Thus, we were able to test every feature introduced for our game.
 
