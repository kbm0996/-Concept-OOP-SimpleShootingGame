# 간단한 슈팅 게임 (객체지향)
## 📢 개요
 ``객체지향(object-oriented) 프로그래밍``은 실제 세계처럼 스스로 데이터를 처리하는 객체(object)들이 서로 메세지를 보내고 소통하는 것처럼 프로그래밍하는 것이다.
  
## 💻 슈팅 게임
 캐릭터를 방향키로 움직이고 스페이스바로 투사체를 발사하여 적을 섬멸

  ![capture](https://github.com/kbm0996/SimpleShootingGame-Procedural-/blob/master/GIF.gif?raw=true)
  
  **figure 1. Shooting Game(animated)*


## 📐 워크플로우
  ![objectdiagram](https://github.com/kbm0996/SimpleShootingGame-OOP-/blob/master/1ObjectDiagram.jpg)
  
  **figure 2. Object Diagram*

  ![flowchart1](https://github.com/kbm0996/SimpleShootingGame-OOP-/blob/master/2Flowchart-main.JPG)
  
  **figure 3. Workflow-main()*

  ![flowchart1](https://github.com/kbm0996/SimpleShootingGame-OOP-/blob/master/3Flowchart-Run.JPG)
  
  **figure 4. Workflow-Run()*

  ![flowchart1](https://github.com/kbm0996/SimpleShootingGame-OOP-/blob/master/4Flowchart-Update.JPG)
  
  **figure 5. Workflow-Update()*
  
## 📑 구성
**📋 _config.h** : 게임 설정을 하드코딩으로 변경할 수 있는 헤더

**📋 _main.cpp** : 프로그램이 실행되는 메인 함수

**📋 CSceneMgr.h/cpp** : Scene들을 총체적으로 관리하는 객체

**📋 LinkedList.h** : Objectlist 역할. 반복자 패턴이 사용된 연결리스트

### 📂 Objects

**📋 BaseObject.h** : 이하 객체들의 부모 클래스. 인터페이스 역할을 하는 순수 가상 함수들을 포함하는 추상 클래스

📋 CPlayer.h/cpp, 📋 CEnemy.h/cpp, 📋 CBoss.h/cpp, 📋 CBossBullet.h/cpp, 📋 CBullet.h/cpp

### 📂 Render

**📋 Console.h/cpp** : Buffer를 Console에 출력

**📋 Draw.h/cpp** : Player, Enemy, Boss, Bullet, Scene등을 Buffer에 반영

### 📂 Scenes

**📋 BaseScene.h** :  이하 Scene 객체들의 부모 클래스. 인터페이스 역할을 하는 순수 가상 함수들을 포함하는 추상 클래스

📋 CScene_1Title.h/cpp, 📋 CScene_2Gameover.h/cpp, 📋 CScene_Stage1.h/cpp, 📋 CScene_Stage2.h/cpp
