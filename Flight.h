
#define MAX 50

typedef struct
{                                   //航班信息
	char FlightNum[10];             //航班号
	char StartPoint[10];			//起点站
	char EndPoint[10];				//终点站
	char StartTime[15];				//起飞时间
	char EndTime[15];				//到达时间
	char PlaneType[10];				//机型
	int price;						//票价
}flightInfo;

typedef struct {
	flightInfo infos[MAX];
	int length;					 //航班个数
}flightLists;

//选择需要通过的信息查询航班信息
void SearchSelectOne(flightLists *info);

//通过航班号查询
void searchByFlightNum(flightLists *info);

//通过起点站查询
void searchByStartPoint(flightLists *info);

//通过终点站查询
void searchByEndPoint(flightLists *info);

//通过终点站查询
void searchByStartTime(flightLists *info);

//通过到达时间查询
void searchByEndTime(flightLists *info);

//通过机型查询
void searchByPlaneType(flightLists *info);