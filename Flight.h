
#define MAX 50                      //航班数量最大为50

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
	int length;					 //航班数量
}flightLists;


//选择操作(FlightSystem.c)
void SelectOptions(flightLists *info);



/** ** ** ** ** ** ** 录入(FlightInfoInput.c) ** ** ** ** ** ** ** ** ** ** ** **/


//选择需要通过的信息录入航班信息
void InputSelectOne(flightLists *info);

//导入原有的数据文件信息
void InputByOld(flightLists *info);

//航班信息录入
void InputInfo(flightLists *info);

//从文件中录入航班信息
void InfoInputByFlie(flightLists *info);

//打印航班信息
void InfoPrint(flightLists *info);

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/



/** ** ** ** ** ** ** 查询(FlightInfoInput.c) ** ** ** ** ** ** ** ** ** ** ** **/

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

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/



/** ** ** ** ** ** ** 排序(FlightInfoSort.c) ** ** ** ** ** ** ** ** ** ** ** **/

//选择需要通过的信息排序航班信息
void SortSelectOne(flightLists *info);

//通过航班号进行升序排序
void SortByFlightNum(flightLists *info);

//通过票价进行升、降序排序
void SortByPrice(flightLists *info);

//打印排序后信息
void SortPrint(flightLists *info);

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/



/** ** ** ** ** ** ** 删除(FlightInfoDelete.c) ** ** ** ** ** ** ** ** ** ** ** **/

//选择需要通过的信息删除航班信息
void DeleteSelectOne(flightLists *info);

//根据航班号删除航班相关信息
void DeleteByFlightNum(flightLists *info, int one);

//根据机型删除航班相关信息
void DeleteByPlaneType(flightLists *info, int one);

//删除操作
void DeleteOptions(flightLists *info, char type[], int one);

/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/




/** ** ** ** ** ** ** 修改(FlightInfoUpdate.c) ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/


//选择需要通过的信息修改航班信息
void UpdateSelectOne(flightLists *info);

//根据航班号修改航班相关信息
void UpdateByFlightNum(flightLists *info);

//根据机型修改航班相关信息
void UpdateByPlaneType(flightLists *info);


//确认所要修改的航班信息
int UpdateWhichOne(flightLists *info, int num[], int j);

//选择修改某一处的航班信息
void UpdateSelect(flightLists *info, int num[], int j);


//修改航班号
void UpdateFlightNum(flightLists *info, int one, int whichOne, int num[], int j);

//修改起点站
void UpdateStartPoint(flightLists *info, int one, int whichOne, int num[], int j);

//修改终点站
void UpdateEndPoint(flightLists *info, int one, int whichOne, int num[], int j);

//修改起飞时间
void UpdateStartTime(flightLists *info, int one, int whichOne, int num[], int j);

//修改到达时间
void UpdateEndTime(flightLists *info, int one, int whichOne, int num[], int j);

//修改机型
void UpdatePlaneType(flightLists *info, int one, int whichOne, int num[], int j);

//修改票价
void UpdatePrice(flightLists *info, int one, int whichOne, int num[], int j);


/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/