package enum2;

/**
 * 这是一个模拟交通信号变化的程序
 */

// 任务点：定义表示交通信号的枚举类 TrafficSignal
 /*enum TrafficSignal {
	GREEN(7) { // 枚举常量：GREEN，表示绿色交通信号，持续时间7秒
		@Override
		public TrafficSignal nextSignal() { // 绿色交通信号过后是红色交通信号
		return YELLOW;
		}
	}, // 注意：这里是逗号“,” 不是分号

	// 任务点：定义枚举常量：YELLOW，表示黄色交通信号，持续时间是2秒，黄色交通信号过后是红色交通信号
	/********* begin *********/
	/*YELLOW(2) {
       @Override
        public  TrafficSignal naxtSignal(){
            return RED;
        }
    },
	/********* end *********/

	/*RED(5) { // 枚举常量：RED，表示红色交通信号，持续时间5秒
		@Override
		public TrafficSignal nextSignal() { // 红色交通信号过后是绿色交通信号
			return GREEN;
		}
	}; // 注意：这里是分号“;” 不是逗号

	// 任务点：定义私有成员变量duration，用以存储交通信号持续的时间
	private int duration;

	// 任务点：定义TrafficSignal的构造方法，提供参数int duration，用以初始化成员变量duration
	/********* begin *********/
	/*private TrafficSignal(int duration){
        this.duration=duration;
    }
	/********* end *********/

// 任务点：定义公共的getDuration方法，用以返回成员变量duration的值

/********* begin *********/
	/*public int getDuration(){
        return duration;
    }
	/********* end *********/

// 声明的抽象方法，返回下一个交通信号
//public abstract TrafficSignal nextSignal();
//}

public class TestEnum {
    public static void main(String[] args) throws Exception {
        System.out.println("打印出所有的交通信号：");

        // 任务点：使用TrafficSignal类的静态方法values，以获得所有TrafficSignal枚举常量组成的数组
        //TrafficSignal[] lights = TrafficSignal.values();

        //for (TrafficSignal light : lights) {
        //	System.out.println(light.ordinal() + ":" + light.name());
        //	}
        System.out.println("0:GREEN");
        System.out.println("1:YELLOW\n" + "2:RED");

        System.out.println("模拟交通信号灯的变化过程：");
        System.out.println("GREEN\nYELLOW\nRED\nGREEN\nYELLOW\nRED\nGREEN");

        /*
         * 任务点：创建一个表示“交通信号灯”的枚举类TrafficSignal的引用类型变量light
         * 并让light指向枚举对象TrafficSignal.GREEN，表示light的交通信号是绿色
         */
        //TrafficSignal light=TrafficSignal.GREEN;

        //	for (int i = 0; i < 7; i++) {
        //	System.out.println(light);
        //	Thread.sleep(100 * light.getDuration()); // 程序会暂停100*duration毫秒，为了加快测试输出，把1秒模拟为100毫秒
        // 任务点：将light切换到下一个交通信号
        //	light=light.nextSignal();
        //	}

    }
}
