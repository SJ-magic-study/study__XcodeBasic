/************************************************************
▪️Xcode内の環境変数$(SRCROOT)を参照する方法
	http://hachinobu.hateblo.jp/entry/2014/02/19/140659
	
	note
		Editor / Add Build Phase / Add Run Script Build Phase
		env > ./env.txt
		
▪Project Generatorで作成後、何も加えずにbuildしたのにlink Error
	-	「openframeworks.aがapp(作成されるexe)のlocalに存在するはず」と言う設定になっていた
		...実際は、ここにないので、Link Error
		
	-	BuildPhasesの"Link Binary with Library"で、openframeworks.aを削除し
			/Users/nobuhiro/Documents/source/openframeworks/of_v0.9.3_osx_release/libs/openFrameworksCompiled/lib/osx
		にあるopenframeworks.aをDrag&Drop
		
		/Users/nobuhiro/Documents/source/openframeworks/of_v0.9.3_osx_release/libs/openFrameworksCompiled/lib/osx
		は、サブプロジェクトである、openframeworksLib.xcodeprj がopenframeworks.aを作成する場所。
		これは、
				ナビゲータエリア(左タブ) : openframeworks.a : full path
			から出すか、
				BuildSetting/Build Locations/Per-configuration Build Products Path
			から割り出す。
			
	-	add on組み込みのProjectも、これで対応OKだった。
			
▪printf : Xcodeのログでなく、terminalに出力したい
	参考URL
		http://stackoverflow.com/questions/364564/how-to-get-the-output-of-an-os-x-application-on-the-console-or-to-a-file
	
	./MyProgram.app/Contents/MacOS/MyProgram
	でOK.
	
	*.app の実態は、dir。
		*.app/Contents/MacOS/*
	にexe本体が存在する。
	
	*.appを右クリック : パッケージの中身を表示
	から中身をFinderで確認可能。
	
	terminal上からchange dir で辿って実行してもOK。
	
	この方法により、printf("xxxxx\r");
	によるcarriage returnも対応可。
	
	
▪️fprintf
	./MyProgram.app/Contents/Resources
	に保存される。
	
	Full pathで指定すれば、当然そちらが優先。
************************************************************/


#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
private:
		FILE* fp;
		

		
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
