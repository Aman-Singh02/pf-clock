

extern Status 	          Key;                                          // Key Structure
extern RCVR_InitTypeDef  RcvInput;	                                // Recieved data structure
      
extern const int                BitMap_DATA[];

/**************************************[Working Flags]******************************************/

extern FlagStatus  	        Flag_KeyPrg,            	 // Programming Key Debounce
                                Flag_Key1224,           	 // 12/24 Key Debounce
                                Flag_Second,		         // Flag predefined time Interval
				Flag_Toggle,            	 // Flag to toggle LED
				Flag_SegReady,          	 // Segment data Ready for display
				Flag_DigitScan,	        	 // Scan Column for next data
				Flag_SegUpdate,         	 // Update Segemnt with Next Data
				Flag_SLAVEex,           	 // Flag to access Slave
				Flag_MASTERin,          	 // Flag to access Master
				Flag_Prog,              	 // Flag for Programming Mode
				Flag_1224mode,          	 // Flag for 12/14 mode
				Flag_GPSValid,          	 // GPS Datsa Valid
				Flag_RxValid,           	 // Recieved Data Valid
				Flag_NewDataReady,      	 // New Data Arrived
				Flag_GPSDataReady,      	 // GPS Data Avilable
				Flag_MCheckTime,        	 // Check Time of Master Clock
				Flag_Init,              	 // Initialization
				Flag_RxDataReady;   		 // Rx Data Avilable

/***********************************[Variables Definition]***************************************/

extern unsigned char 	        GPS_DataIn[GPS_BufferSize],      // GPS Input Buffer
                                Rcv_DataIn[DATA_BufferSize],     // Reciever Buffer
				TxBuffer[30],                    // Data to be transmitted
				Clock_Mode,             	 // Clock Mode
				ModeCounter,            	 // Counter to check clock status
				ReCheck_Time,           	 // Recheck GPS avalibility
				LED_Color,              	 // Mode LED indicator
				Display_DATA[4],        	 // Data to be displayed
				DISP_HH,			 // For displaying Hour
				GPS_HH,				 // GPS Hour
				GPS_MM,				 // GPS Minute
				GPS_SS,				 // GPS Second
				/*RCV_HH,                	 // Recieved Data Hour				//comment out
				RCV_MM,                  	 // Recieved Data Min				//comment out
				RCV_SS,                  	 // Recieved Data Second*/			//comment out
				MSTin_HH,			 // Master Hour
				MSTin_MM,			 // Master Minute
				MSTin_SS,			 // Master Second
				SLVex_HH,			 // Slave Hour
				SLVex_MM,			 // Slave Minute
				SLVex_SS,		         // Slave Second
				PRG_HH,                 	 // Program Hour
				PRG_MM,                          // Program Minute
				//Old_SS,			 // Previous Second Value			//comment out
				Key_State,             		 // Variable for Key Scan
				Key_Entry,             		 // Key Entered by User
				Prog_State,            		 // Program Mode
				DayInt,                		 // Day Time Intensity
				NightInt,              		 // Night Time Intensity
				DutyCycle,             		 // Intensity Duty Cycle
				RxState_GPS,			 // GPS Reciever State
				RxState,               		 // Clock Reciever State
				NextDigit,             		 // Next Digit to be scaned
				BoardAddress,			 // Board Physical Address
				RcvCnt_GPS                       // Reciever Counter for Recieving GPS Data
				RcvCnt                           // Reciever Counter for recieving data
				DigitCount                       // Digit Scan Count

extern unsigned short           SegMult,               		 // Segment multiplier for scanning
				DigitDisplay[2],       		 // Data to be displayed
				Key_Time[4],            	 // Key Time Input
				crc,                       	 // CRC for verifiation
				Sec_Tick,               	 // Second Tick Counter
				DisplayData,                     // Data to Be displayed
				Scan_Time,                       // Key Scan Time
				GP_Counter;			 // General Purpose Counter


extern unsigned long            RTC_Countin;                     // Counter for Slave RTC



