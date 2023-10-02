#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
struct one{
	string name;
	int s;
	int age;
	//金钱 
	int money1,money2,money3;//金加隆，银西可，铜纳特
	//魔杖，魔法 
	int magic;
	int magican[100];
	int magnum;
	//外观 
	string _1;//发色 
	string _2;//皮肤 
	string _3;//眼睛 
	string _4;//衣服 
	string w; 
	//物品
	int thing[100];
	int thnum; 
};
string se[2]={"先生","女士"}; //称谓 
string adj[2]={"帅气","美丽"};//adj 
string mag[8]={"凤凰尾羽紫衫木魔杖","独角兽毛山楂木魔杖","雷鸟羽毛雪杉木魔杖","火龙神经硬木魔杖","独角兽毛雪松木魔杖","凤凰尾羽柳木魔杖","赤木凤凰尾羽魔杖","铁木夜骑尾毛魔杖"}; 
string gic[100]={"除你武器","飞来","障碍重重","护神护卫","门牙塞大棒","钻心剜骨","阿瓦达索命","魂魄出窍","神锋无影"};//魔法 
string thing[4]={"光轮2001","魔法石","白鲜香精"}; //物品 
int magn=8; //魔杖种类数量 
string drink[2]={"黄油啤酒","火焰威士忌"};//饮料种类 
int dn=2;//饮料种类数量 
int dw[2]={5,10};//饮料价格 
string school[6]={"无","格兰芬多","赫奇帕奇","拉文克劳","斯莱特林","阿兹卡班"};//五大学院(doge) 
int sflag;
int life;
one player;//玩家 
//转场
void jump(){
	for(int i=0;i<3;i++){
		system("cls");
		cout<<"..."<<endl;
		Sleep(800);
		system("cls");
		cout<<"...."<<endl;
		Sleep(800);
	}
} 
//随机函数
int come(int a,int b){
	srand((int)time(0));
	return (rand()%(b-a+1))+a; 
}
//歇停 
void change(){
	getch();
	system("cls");
}
//开场
void start(){
	cout<<"您好，请告诉我您的姓名：";
	cin>>player.name;
	system("cls");
	cout<<"好的"<<endl; 
	cout<<"还有您的性别，谢谢(男m,女w)：";
	char a;
	cin>>a;
	system("cls");
	if(a=='m'){
		player.s=0; 
		cout<<"您好,"<<player.name<<"先生"; 
	}
	else if(a=='w'){
		player.s=1;
		cout<<"您好,"<<player.name<<"小姐"; 
	}
	else{
		cout<<"您很喜欢开玩笑啊，梅林也许也喜欢，那您便无性吧."<<endl;
		player.s=-1; 
	}
	change();
}
//捏脸 
void look(){
	cout<<"请描述您的样貌：(一个或多个形容词)"<<endl;
	cout<<"头发：";
	cin>>player._1;
	cout<<"皮肤：";
	cin>>player._2;
	cout<<"眼睛：";
	cin>>player._3;
	cout<<"衣服：";
	cin>>player._4;
	system("cls");
	cout<<"哦，"<<adj[player.s]<<"的"<<se[player.s]<<","<<endl;
	cout<<"您"<<player._1<<"发丝披在脑后,"<<player._3<<"的眼瞳中闪着光芒,"<<player._4<<"华丽的同时也不失优雅。"<<endl;
	cout<<"您很"<<adj[player.s]<<se[player.s]<<"。"<<endl;
	change();
	cout<<"哦对了，由于您没有房子，破釜酒吧13号，以后就是你的家了。";
	Sleep(100);
	change();
}
//支付 
int pay(int a,int b,int c){
	//1 17 29 
	int ans1,ans2;
	ans1=a*17*29+b*29+c;
	ans2=player.money1*17*29+player.money2*29+player.money3;
	cout<<"您有"<<player.money1<<"加隆,"<<player.money2<<"西可,"<<player.money3<<"纳特"<<endl; 
	if(ans2<ans1){
		cout<<"您买不起啊"<<endl;
		cout<<"您只有"<<player.money1<<"加隆,"<<player.money2<<"西可,"<<player.money3<<"纳特"<<endl; 
		cout<<"哦，老板，不好意思今天出门忘带钱了，我不买了，谢谢啊"<<endl;
		change(); 
		return 1;
	}
	int ans3=ans2-ans1;
	int x,y,z;
	x=ans3/(29*17);
	y=(ans3-x*29*17)/29;
	z=ans3-x*29*17-y*29; 
	player.money1=x;player.money2=y;player.money3=z;
	cout<<"您现在有"<<player.money1<<"加隆,"<<player.money2<<"西可,"<<player.money3<<"纳特"<<endl; 
	return 0;
}
//第一部，哈利波特与魔法石
//破釜酒吧 
void bar1(){
	cout<<"你走进了破釜酒吧，找了一个空位坐了下来。"<<endl;
	change();
	cout<<"要来点什么吗?(要Yes,...或不要No,...)"<<endl;
	string a;
	cin>>a;
	if(a[0]=='Y'){
		cout<<"等我想想。"<<endl;
    	cout<<"1.黄油啤酒 5西可 2.火焰威士忌 10西可"<<endl;
		int c;
		cin>>c;
		cout<<"一杯"<<drink[c-1]<<",谢谢"<<endl;
		pay(0,0,dw[c]);
		cout<<"你坐了下来,静静欣赏着酒馆内的人山人海。"<<endl;
		change();
		cout<<"天色逐渐晚了下来,你回到了房间,躺在床上，睡了过去。"<<endl;
		change(); 
	}
	if(a[0]=='N'){
		cout<<"不了谢谢。"<<endl;
		change();
	}
} 
//霍格沃茨入学信
void letter(){
	cout<<"第二天清晨，你从床上起来，就看见一只雪白的猫头鹰正用长喙敲击着你的窗户"<<endl;
	change();
	cout<<"你站起身打开窗户，从猫头鹰脚下取下了一封有着四色图案的来信，并缓缓展开"<<endl;
	change();
	printf(
		"第一页\n"
	"霍格沃茨魔法学校\n\n"
	"校长：阿不思·邓布利多\n"
	"（国际巫师联合会会长、梅林爵士团一级、大魔法师、威森加摩首席魔法师）\n"
	"HOGWARTS SCHOOL of WITCHCRAFT and WIZARDRY\n\n"
	"Headmaster: Albus Dumbledore\n"
	"(Order of Merlin, First Class, Grand Sorc., Chf. Warlock,\n"
	"Supreme Mugwump, International Confed. of Wizards)\n"
	"亲爱的先生：\n\n"
	"Dear Mr. Potter,\n\n"
	"我们愉快地通知您，您已获准在霍格沃茨魔法学校就读。随信附上所需书籍及装备一览表。\n\n"
	"We are pleased to inform you that you have been accepted at Hogwarts School of Witchcraft and Wizardry. Please find enclosed a list of all necessary books and equipment.\n\n"
	"学期定于九月一日开始。我们将于七月三十一日前静候您的猫头鹰带来您的回信。\n\n"
	"Term begins on 1 September. We await your owl by no later than 31 July.\n\n"
	"副校长（女）\n"
	"米勒娃·麦格　谨上\n\n"
	"Yours sincerely,\n"
	"Minerva McGonagall\n"
	"Deputy Headmistress\n"
	);
	change();
	cout<<"另外，鉴于您的身份原因，霍格沃茨将每年给您下发700加隆的助学金"<<endl;
	player.money1+=100;
	change();
} 
//奥利凡德
void alfand(){
	cout<<"早晨,你收起了霍格沃茨的入学信,"<<player._3<<"眼睛里闪着别样的光芒。"<<endl;
	change();
	cout<<"突然间你想起了什么似的，下楼来到了酒吧后的垃圾桶旁,虽然你没有魔杖，但你还是用魔力打开了大门，直奔奥利凡德魔杖店而去"<<endl;
	change();
	cout<<"你走进了魔杖店里，展柜里紫色的纱布上，一根魔杖平躺着，向他人展示着。"<<endl;
	change();
	cout<<"店里并不宽敞，甚至有些狭窄，以为白发银眸的老人正精心擦拭着一根魔杖。"<<endl;
	change();
	cout<<"看见你走了进来，老人转过身，露出了笑容。"<<endl;
	change();
	cout<<"孩子，你是要买魔杖吗？"<<endl;
	change();
	cout<<"你点了点头。"<<endl;
	change();
	cout<<"那，孩子你是用左手还是右手呢？（左l，右r）"<<endl;
	string a;
	cin>>a;
	change();
	if(a[0]=='l'){
		cout<<"左手"<<endl; 
	} 
	else{
		cout<<"右手"<<endl;
	}
	change();
	cout<<"好的，孩子来试试这根，12英寸，独角兽毛樱花木魔杖，有点敏感，你挥一下试试"<<endl;
	change();
	cout<<"不对这根不行,来这根..."<<endl;
	change();
	jump();
	change();
	cout<<"对，就是这根,";
	int b=come(0,magn-1);
	cout<<mag[b]<<endl;
	player.magic=b;
	change();
	cout<<"恭喜你找到了自己的魔杖，孩子。"<<endl; 
	cout<<"“多少钱，先生？”"<<endl;
	cout<<"7个加隆,孩子。"<<endl;
	pay(7,0,0); 
	cout<<"好的，先生"<<endl;
	change(); 
}
//九又四分之三站台 
void train(){
	int s1=0,s2=0,s3=0,s4=0;
	cout<<"买完魔杖后，你买完教材就开始学习魔咒。"<<endl;
	pay(10,0,0); 
	change();
	jump();
	change();
	cout<<"你学会了缴械咒和飞来咒（自己买的课外书）"<<endl;
	change();
	player.magican[player.magnum]=0;
	player.magnum++;
	player.magican[player.magnum]=1;
	player.magnum++;
	cout<<"九月一号" ;
	cout<<"清晨，你早早准备好了行李，准备前往9又4分之3站台"<<endl;
	change();
	cout<<"你来到了那面墙前，却发现一位身材瘦削的男孩正紧张的四处张望。"<<endl;
	cout<<"1.询问男孩发生了什么 2.叫来警卫把他抓走 3.阿瓦达索命"<<endl;
	int a;
	cin>>a;
	system("cls"); 
	switch(a){
		case 1:{
			cout<<"你走了过去,来到了男孩身边，低声问道"<<endl;
			change(); 
			cout<<"你是在找九又四分之三站台吗?"<<endl;
			change();
			cout<<"男孩，回过头有些局促的看着你，点了点头。"<<endl;
			change();
			cout<<"你对着男孩笑了笑，没事，从这面墙穿过去就好了"<<endl;
			change();
			cout<<"男孩局促一笑，道了声谢谢，便钻了进去"<<endl;
			change();
			cout<<"你也紧跟着走了进去"<<endl;
			change();
			s1++;
			break;
		}
		case 2:{
			cout<<"你走向了另一边，叫来了警卫"<<endl;
			change();
			cout<<"警卫先生，这个孩子不知道为什么，一直东张西望的，您看看，不会是小偷吧"<<endl;
			change();
			cout<<"警卫听后，对你笑了笑，又转头看向了一脸紧张的男孩，眯了眯眼，大步走了过去"<<endl;
			change();
			cout<<"小子，你到底是在干什么？我跟你说了，这里没有什么九又四分之三站台，我警告你，你要是想偷东西，哼哼"<<endl;
			change();
			cout<<"随即他又转过头对你笑了笑，"<<adj[player.s]<<se[player.s]<<"这里没有什么事，您可以走了，我会处理他的"<<endl;
			change();
			cout<<"你对着警卫笑了笑，“没关系”"<<endl;
			change();
			cout<<"说着，便转身离去"<<endl;
			s3++;
			break;
		}
		case 3:{
			cout<<"你不会这个魔法"<<endl;
			change();
			cout<<"你失落的叹了口气"<<endl;
			change();
			cout<<"转身离去"<<endl;
			change();
			s4++;
			break;
		} 
	}
	cout<<"你走进了火车里，随便找了一个空包厢坐了下来,从书包里掏出一本书，翻阅了起来"<<endl;
	change();
	jump();
	change();
	cout<<"一阵敲门声响了起来"<<endl;
	change();
	cout<<"你关上书,起身打开了门"<<endl;
	change();
	cout<<"一位头发乱蓬蓬的小女巫出现在了你的面前"<<endl;
	change();
	cout<<"你看了看女孩"<<endl;
	change();
	cout<<"我是"<<player.name<<",你是？";
	change();
	cout<<"女孩笑了起来“哦，我叫赫敏·格兰杰”"<<endl;
	change();
	cout<<"一个男孩也支支吾吾的说到，“我叫纳威·隆巴顿”"<<endl;
	change();
	cout<<"你笑了笑，说“有什么事吗，格兰杰小姐？”"<<endl;
	change();
	cout<<"纳威的蟾蜍不见了，你能帮我们在你的包厢里找找吗?"<<endl;
	cout<<"1.帮纳威赵蟾蜍 2.蟾蜍飞来 3.不理不睬" <<endl;
	cin>>a;
	switch(a){
		case 1:{
			cout<<"哦，我看看"<<endl;
			jump();
			change();
			cout<<"抱歉，真的没有"<<endl;
			s2++;
			break;
		}
		case 2:{
			cout<<"我会帮你们的"<<endl;
			change();
			cout<<"蟾蜍飞来"<<endl;
			change();
			cout<<"一只蟾蜍从走廊里疾驰而来，迅速飞到了你的手里"<<endl;
			cout<<"你将它递给了纳威"<<endl;
			change();
			cout<<"谢谢，纳威感激的说道"<<endl;
			change();
			cout<<"赫敏瞪大了眼睛,这是飞来咒"<<player.name<<se[player.s]<<endl;
			cout<<"这不是五年级魔咒课上的内容吗？"<<endl;
			change();
			cout<<"你笑着点了点头"<<endl;
			cout<<"赫敏有些呆滞，喃喃自语着：“看来我还是没有做好预习”"<<endl;
			cout<<"赫敏向你表达了感谢过后，便拉着纳威，转身离去了"<<endl;
			change();
			s3++; 
			break;
		}
		case 3:{
			cout<<"你不予理睬，直接关上了房门说到“没有，不用找了”"<<endl;
			change();
			cout<<"你做回了椅子上继续看起了书"<<endl;
			s4++;
			break;
		}
	}
	cout<<"看了一会，视线逐渐模糊了起来" <<endl;
	change();
	cout<<"然后便逐渐睡了过去"<<endl;
	jump();
	change();
	cout<<"当你再次醒来的时候，霍格沃茨宏伟的中世纪城堡，已经出现在了你的面前"<<endl;
	change();
	cout<<"你赶紧换好了校服,整理好了行李"<<endl;
	change();
	cout<<"火车停了下来,你走下车。"<<endl;
	change();
	cout<<"一个魁梧的巨大身影出现在了你的视线之中"<<endl;
	change();
	cout<<"一年级新生跟我来，巨大的身影的主人喊道："<<endl;
	change();
	cout<<"你跟了上去"<<endl;
	change();
	cout<<"你们度过了黑湖，看到了一位女巫"<<endl;
	change();
	cout<<"女巫喊道：“海格，把他们交给我吧。”" <<endl;
	change();
	cout<<"海格点了点头"<<endl;
	change();
	cout<<"你走了上去看到了之前那个男孩，你看到了他头上的伤疤"<<endl;
	change();
	cout<<"你回忆了一下魔法史的内容，顿时想了起来，这位是哈利·詹姆·波特"<<endl;
	change();
	cout<<"你又看见了他身边的红头发男孩以及他的手里的老鼠"<<endl;
	cout<<"1.阿瓦达索命 2.前去攀谈"<<endl;
	cin>>a;
	change();
	switch(a){
		case 1:{
			cout<<"你虽然不会这个咒语，但强大的杀意充斥了你的内心，你的灵魂感受到了撕裂般的痛楚，但你的魔杖仍平举身前。"<<endl;
			change();
			cout<<"一道惨绿色的光芒直至那只老鼠"<<endl;
			change();
			cout<<"麦格教授这才反应了过来，拔出了魔杖，“除你武器”，她惊讶及了，抬手一道红光射向了你"<<endl;
			change();
			cout<<"但还是晚了一步"<<endl;
			change();
			cout<<"罗恩同着他那只老鼠一起化为了尸体"<<endl;
			change();
			cout<<"同时红光也挑飞了你的魔杖"<<endl;
			change();
			cout<<"你倒在了地上,昏了过去"<<endl;
			change();
			cout<<"审判"<<endl;
			cout<<"你有什么想说的吗？"<<player.name<<se[player.s]<<endl;
			cout<<"你淡淡的道没有"<<endl;
			change();
			jump();
			cout<<"你以你一个人的命和一条无辜的生命拯救了这个世界"<<endl;
			change();
			cout<<"阿兹卡班平凡的一生，值得"<<endl;
			change();
			life=-1;
			return;
			break;
		}
		case 2:{
			cout<<"你走上去与他们交谈了起来："<<endl;
			change();
			cout<<"我是"<<player.name<<",你是哈利·波特吧，那你是？你看向红头发的男孩"<<endl;
			change();
			cout<<"哦，我是罗恩·韦斯莱"<<endl;
			change();
			cout<<"你笑着和他们说着话"<<endl;
			change();
			cout<<"过了一会，麦格教授走了过来道，分院仪式开始了，我点到名字的就进来"<<endl; 
			change();
			break;
		}
	}
	int ans=0,ansi=-1;
	if(s1>=ans){
		if(s1==ans){
			if(come(0,1)==1){
				ans=s1;
			}
		}
		else{
			ans=s1;
			ansi=1;
		}
	}
	if(s2>=ans){
		if(s2==ans){
			if(come(0,1)==1){
				ans=s2;
			}
		}
		else{
			ans=s2;
			ansi=2;
		}
	}	
	if(s3>=ans){
		if(s3==ans){
			if(come(0,1)==1){
				ans=s3;
			}
		}
		else{
			ans=s3;
			ansi=3;
		}
	}
	if(s4>=ans){
		if(s4==ans){
			if(come(0,1)==1){
				ans=s4;
			}
		}
		else{
			ans=s4;
			ansi=4;
		}
	}
	sflag=ansi;
	return;
}
//分院仪式
void choose(){
	cout<<"分院帽开始歌唱"<<endl;
	change(); 
	printf(
		"你们也许觉得我不算漂亮，\n"
		"但千万不要以貌取人，\n"
		"如果你们能找到比我更漂亮的帽子，\n"
		"我可以把自己吃掉。\n"
		"你们可以让你们的圆顶礼帽乌黑油亮，\n"
		"让你们的高顶丝帽光滑挺括，\n"
		"我可是霍格沃茨测试用的魔帽，\n"
		"自然比你们的帽子高超出众。\n"
		"你们头脑里隐藏的任何年头，\n"
		"都躲不过魔帽的金睛火眼，\n"
		"戴上它试一下吧，我会告诉你们，\n"
		"你们应该分到哪一所学院。\n"
		"你也许属于格兰芬多，\n"
		"那里有埋藏在心底的勇敢，\n"
		"他们的胆识、气魄和豪爽，\n"
		"使格兰芬多出类拔萃；\n"
		"你也许属于赫奇帕奇，\n"
		"那里的人正直忠诚，\n"
		"赫奇帕奇的学子们坚忍诚实，\n"
		"不畏惧艰辛的劳动；\n"
		"如果你头脑精明，\n"
		"或许会进智慧的老拉文克劳，\n"
		"那些睿智博学的人，\n"
		"总会在那里遇见他们的同道；\n"
		"也许你会进斯莱特林，\n"
		"也许你在这里交上真诚的朋友，\n"
		"但那些狡诈阴险之辈却会不惜一切手段，\n"
		"去达到他们的目的。\n"
		"来戴上我吧！不必害怕！\n"
		"千万不要惊慌失措！\n"
		"在我的手里（尽管我连一只手也没有）\n"
		"你绝对安全\n"
		"因为我是一顶会思想的魔帽！\n"
	);
	cout<<"分院帽终于唱完了，麦格教授叫起了名字"<<endl;
	change();
	cout<<"终于，麦格教授喊道：“下一位"<<player.name<<"”"<<endl;
	change();
	cout<<"你心里有些许忐忑，走到分院帽旁边坐下，将他带到了头上"<<endl;
	change();
	cout<<"分院帽：“我想我知道把你分到哪个学院了”"<<endl;
	change();
	cout<<"分院帽(高声):"<<school[sflag]<<endl;
	cout<<school[sflag]<<"响起了一片掌声"<<endl;
	change(); 
}
void Bed(){
	int a;
	switch(sflag){
		case 1:{//格兰芬多 
			cout<<"今天的口令是”火麟“"<<endl;
			change();
			cout<<"你跟随着级长和哈利，罗恩攀谈着，走进了格兰芬多的公共休息室，红金色的装饰物，是那么的热情似火"<<endl;
			change();
			cout<<"开始分寝室了"<<endl;
			change();
			if(player.s==0){
				cout<<"你和哈利和罗恩分到了一个寝室"<<endl;
			}
			else{
				cout<<"你和赫敏分到了一个寝室"<<endl;
			}
			cout<<"1.直接睡觉 2.和室友交流 3.练习魔咒";
			cin>>a;
			switch(a){
				case 1:{
					cout<<"你直接睡了过去，室友似乎想跟你说话，但你毫不理睬"<<endl;
					change();
					break;
				}
				case 2:{
					cout<<"你和室友交流到深夜，一股疲倦颖上心头，你沉沉的睡了过去"<<endl;
					change();
					break;
				} 
				case 3:{
					cout<<"你开始练习魔咒"<<endl;
					jump();
					change();
					cout<<"你学会了障碍咒"<<endl; 
					player.magican[player.magnum]=2;
					player.magnum++; 
					break;
				}
			}
			break;
		}
		case 2:{//赫奇帕奇 
			cout<<"你随着级长来到了地下一层，进入了赫奇帕奇公共休息室"<<endl;
			change();
			cout<<"你直接找了一个寝室就住了下来"<<endl;
			cout<<"1.去厨房偷吃 2.睡觉"<<endl;
			change();
			cin>>a;
			switch(a){
				case 1:{
					cout<<"你偷偷等其他人都睡了后，溜出了房门"<<endl;
					change();
					cout<<"你悄悄来到公共休息室旁边的壁画前，挠了挠那只梨子，梨子先是一阵大笑，然后变成了一只门把手"<<endl;
					change();
					cout<<"你推门走了进去，一只家养小精灵凑了上来，给你准备了许多饼干与布丁，你大快朵颐后，回了休息室"<<endl;
					change();
					cout<<"你倒在床上，不一会便睡了过去"<<endl;
					change(); 
					break;
				}
				case 2:{
					cout<<"你倒床就睡"<<endl;
					change(); 
					break;
				}
			}
			break;
		}
		case 3:{//拉文克劳 
			cout<<"你爬上八楼，来到了拉文克劳的公共休息室"<<endl;
			change();
			cout<<"哦，请问幽灵和阴尸谁更长寿?"<<endl;
			cout<<"1.死去的东西无法用寿命衡量 2.幽灵，至少它还有意识 3.阴尸，只要对我来说他还有价值，那他就无疆"<<endl;
			cin>>a;
			change();
			switch(a){
				case 1:{
					cout<<"额，有道理，请进"<<endl;
					change();
					cout<<"你走进休息室，拿了一本书开始翻阅，过了一会，看着看着你就睡了过去"<<endl;
					change();
					break;
				} 
				case 2:{
					cout<<"哦，不错的辩论，请进"<<endl;
					change();
					cout<<"你走进休息室，拿了一本书开始翻阅，过了一会，看着看着你就睡了过去"<<endl;
					change();
					break;
				}
				case 3:{
					cout<<"哦，你真该去斯莱特林,回答错误"<<endl;
					change();
					cout<<"你在门口让级长帮你开了门"<<endl;
					change();
					cout<<"你走进休息室，拿了一本书开始翻阅，过了一会，看着看着你就睡了过去"<<endl;
					change();
					break;
				}
			}
			break;
		}
		case 4:{//斯莱特林 
			cout<<"”口令：纯血“"<<endl;
			cout<<"你走进了，斯莱特林的地下休息室"<<endl;
			change();
			cout<<"1.睡觉 2.练习魔咒"<<endl;
			cin>>a;
			switch(a){
				case 1:{
					change();
					cout<<"你走拿了一本书开始翻阅，过了一会，看着看着你就睡了过去"<<endl;
					break;
				}
				case 2:{
					change();
					cout<<"你开始练习魔咒"<<endl;
					jump();
					change();
					cout<<"你学会了一个小恶咒门牙赛大棒"<<endl;
					player.magican[player.magnum]=4;
					player.magnum++;
					break;
				} 
			}
			break;
		}
	}
}
void Class(){
	int a;
	cout<<"上课的时间很快"<<endl;
	change();
	cout<<"很快，你迎来了你的第一堂飞行课"<<endl;
	change();
	cout<<"霍奇夫人拿着愈多扫帚来到了你们面前"<<endl;
	change();
	cout<<"霍奇夫人说到，这届飞行课，我讲一下基本的动作要领"<<endl;
	change();
	jump();
	cout<<"好了大家可以自己试一下"<<endl;
	cout<<"你站在了你的扫帚旁喊道 起来"<<endl;
	change();
	cout<<"扫帚闻声飞起"<<endl;
	change();
	cout<<"霍奇夫人赞许的看了你一眼"<<endl;
	change();
	cout<<"因为你的天赋，"<<school[sflag]<<"加5分"<<endl;
	change(); 
	switch(sflag){
		case 1:{
			cout<<"纳威的扫帚突然不受控制的飞了起来，在空中四处穿行"<<endl;
			cout<<"1.扫帚飞来 2.看好戏"<<endl;
			cin>>a;
			change();
			switch(a){
				case 1:{
					cout<<"你喊道，扫帚飞来"<<endl;
					cout<<"扫帚连着纳威一起飞了过来,把你直接栽在了地上"<<endl;
					change();
					cout<<"你晕了过去"<<endl;
					change();
					cout<<"过了好久，你才从医务室里醒了过来"<<endl;
					cout<<"成就：“格兰芬多份勇猛”"<<endl;
					change(); 
					break;
				} 
				case 2:{
					cout<<"霍奇夫人把纳威救了下来，带他去了医务室"<<endl;
					change();
					cout<<"她回头说到：“在我不在的时候，不要动扫帚，不然还不等你们说一声魁地奇，就要被开除出霍格沃茨了”"<<endl;
					change();
					cout<<"马尔福在霍奇走后，颓然拿出了纳威的及一球"<<endl;
					change();
					cout<<"开始显摆"<<endl;
					cout<<"你冲过去强求"<<endl;
					change();
					cout<<"双脚一蹬便飞在了空中"<<endl;
					change();
					cout<<"你和马尔福在空中对峙着"<<endl;
					change();
					cout<<"突然，你猛的发起了进攻"<<endl;
					change();
					cout<<"一个俯冲，撞翻马尔福，抢回了记忆球"<<endl;
					change();
					cout<<"格兰芬多一阵欢呼"<<endl;
					change();
					cout<<"哦，你们在干什么？"<<endl;
					change();
					cout<<"麦格教授走了过来，询问情况后，叫走了你"<<endl;
					change();
					cout<<"麦格教授把你带到了伍德面前"<<endl;
					change();
					cout<<"伍德，我给你找到一个好苗子"<<endl;
					change();
					jump();
					cout<<"就这样，你得到一个光轮2000，并成为了霍格沃茨找球手"<<endl;
					change();
					break;
				}
			}
			break;
		}
		case 2:{
			cout<<"接下来，你们练习飞行，平稳度过了这节课"<<endl;
			change();
			break;
		}
		case 3:{
			cout<<"接下来，你们练习飞行，平稳度过了这节课"<<endl;
			change();
			break;
		}
		case 4:{
			cout<<"纳威的扫帚突然不受控制的飞了起来，在空中四处穿行"<<endl;
			cout<<"1.扫帚飞来 2.看好戏"<<endl;
			cin>>a;
			change();
			switch(a){
				case 1:{
					cout<<"你喊道，扫帚飞来"<<endl;
					cout<<"扫帚连着纳威一起飞了过来,把你直接栽在了地上"<<endl;
					change();
					cout<<"你晕了过去"<<endl;
					change();
					cout<<"过了好久，你才从医务室里醒了过来"<<endl;
					cout<<"成就：“斯莱特芬多”"<<endl;
					change(); 
					break;
				} 
				case 2:{
					cout<<"霍奇夫人把纳威救了下来，带他去了医务室"<<endl;
					change();
					cout<<"她回头说到：“在我不在的时候，不要动扫帚，不然还不等你们说一声魁地奇，就要被开除出霍格沃茨了”"<<endl;
					change();
					cout<<"马尔福在霍奇走后，颓然拿出了纳威的及一球"<<endl;
					change();
					cout<<"开始显摆"<<endl;
					cout<<"哈利冲过去强求"<<endl;
					change();
					cout<<"双脚一蹬便飞在了空中"<<endl;
					change();
					cout<<"哈利和马尔福在空中对峙着"<<endl;
					change();
					cout<<"突然，哈利猛的发起了进攻"<<endl;
					change();
					cout<<"一个俯冲，撞翻马尔福，抢回了记忆球"<<endl;
					change();
					cout<<"格兰芬多一阵欢呼"<<endl;
					change();
					cout<<"哦，你们在干什么？"<<endl;
					change();
					cout<<"麦格教授走了过来，询问情况后，叫走了哈利"<<endl;
					change();
					cout<<"麦格教授把哈利带到了伍德面前"<<endl;
					change();
					cout<<"伍德，我给你找到一个好苗子"<<endl;
					change();
					jump();
					cout<<"就这样，哈利得到一个光轮2000，并成为了霍格沃茨找球手"<<endl;
					change();
					break;
				}
			}
			break;
		}
	} 
}
//主函数 
void first(){//初期 
	start();
	look();
	bar1();
	letter();
	alfand();
	train();
	if(life==-1){
		change();
		cout<<"你死了"<<endl;
		return;
	}
	choose();
	Bed();
	Class(); 
}
//void second(){
//	
//} 
//void third(){
//	
//}
//void fourth(){
//	
//}
//void fivth(){
//	
//}
//void sixth(){
//	
//}
//void seventh(){
//	
//} 
int main(){
	first();
	if(life==-1){
		change();
		cout<<"你死了"<<endl;
		return 0;
	}
//	second();
//	if(life==-1){
//		change();
//		cout<<"你死了"<<endl;
//		return 0;
//	}
	return 0;
}
//那是一千多年前的事情，
//我刚刚被编织成形，
//有四个大名鼎鼎的巫师，
//他们的名字流传至今：
//勇敢的格兰芬多，来自荒芜的沼泽，
//美丽的拉文克劳，来自宁静的河畔，
//仁慈的赫奇帕奇，来自开阔的谷地，
//精明的斯莱特林，来自那一片泥潭。
//他们共有一个梦想、一个心愿，
//同时有一个大胆的打算，
//要把年轻的巫师培育成材，
//霍格沃茨学校就这样创办 。
//这四位伟大的巫师
//每人都把自己的学院建立，
//他们在所教的学生身上
//看重的才华想法不一。
//格兰芬多认为，最勇敢的人
//应该受到最高的奖励；
//拉文克劳觉得，头脑最聪明者
//总是最有出息；
//赫奇帕奇感到，最勤奋努力的
//才最有资格进入学院；
//而渴望权力的斯莱特林
//最喜欢那些有野心的少年。
//四大巫师在活着的年月
//亲自把得意门生挑选出来，
//可是当他们长眠于九泉，
//怎样挑出学生中的人才？
//是格兰芬多想出了办法，
//他把我从他头上摘下，
//四巨头都给我注入了思想，
//从此就由我来挑选、评价！
//好了，把我好好地扣在头上，
//我从来没有看走过眼，
//我要看一看你的头脑，
//判断你属于哪个学院！
//-- 引自《哈利·波特与火焰杯》106-107页
//很久以前我还是顶新帽，
//那是霍格沃茨还没有建好，
//高贵学堂的四位创建者，
//以为他们永远不会分道扬镳。
//同一个目标将他们联在一起，
//彼此的愿望是那么相同一致：
//要建成世上最好的魔法学校，
//让他们的学识相传、延续。
//“我们将共同建校，共同教学！”
//四位好友的主意十分坚决，
//然而他们做梦也没有想到，
//有朝一日他们会彼此分裂。
//这个世上还有什么朋友，
//能比斯莱特林和格兰芬多更好？
//除非你算上另一对挚友——
//赫奇帕奇和拉文克劳？
//这样的好事怎么会搞糟？
//这样的友情怎么会一笔勾销？
//唉，我亲眼目睹了这个悲哀的故事，
//所以能在这里向大家细述。
//斯莱特林说：“我们所教的学生，
//他们的血统必须最最纯正。”
//拉文克劳说：“我们所教的学生，
//他们的智力必须高人一等。”
//格兰芬多说：“我们所教的学生，
//必须英勇无畏，奋不顾身。”
//赫奇帕奇说：“我们要教许多人，
//并且对待他们一视同仁。”
//这些分歧第一次露出端倪，
//就引起了一场小小的争吵。
//四位创建者每人拥有一个学院，
//只招收他们各自想要的少年。
//斯莱特林收的巫师如他本人，
//血统纯正，诡计多端。
//只有那些头脑最敏锐的后辈，
//才能聆听拉文克劳的教诲。
//若有谁大胆无畏、喜爱冒险，
//便被勇敢的格兰芬多收进学院。
//其余的人都被好心的赫奇帕奇所接收，
//她把自己全部的本领向他们传授。
//四个学院和它们的创建人，
//就这样保持着牢固而真挚的友情。
//在那许多愉快的岁月里，
//霍格沃茨的教学愉快而和谐。
//可是后来慢慢地出现了分裂，
//并因我们的缺点和恐怖而愈演愈烈。
//四个学院就像四根石柱，
//曾将我们的学校牢牢撑住。
//现在却互相反目，纠纷不断，
//各个都想把大权独揽。
//有那么一段时光，
//学校眼看着就要夭亡。
//无数的吵闹，无数的斗争，
//昔日的好朋友反目成仇。
//后来终于在某一天清晨，
//年迈的斯莱特林突然出走。
//尽管那时纷争已经平息，
//他还是灰心地离我们而去。
//四个创建者只剩下三个，
//从此四个学院的情形，
//再不像过去设想的那样
//和睦相处，团结一心。
//现在分院帽就在你们面前，
//你们都知道了事情的渊源：
//我把你们分进每个学院，
//因为我的指责不容改变。
//但是今年我要多说几句，
//请你们把我的新歌仔细听取：
//尽管我注定要使你们分裂，
//但我担心这样做并不正确。
//尽管我必须履行我的职责，
//把每年的新生分为四份，
//但我担心这样的分类，
//会导致我所惧怕的崩溃。
//哦，知道危险，读懂征兆，
//我们的霍格沃茨面临着危险，
//校外的仇敌正虎视眈眈。
//我们的内部必须紧密团结，
//不然一切都会从内部瓦解。
//我已对你们直言相告，
//我已为你们拉响警报……
//现在让我们开始分院。
