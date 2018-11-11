import java.awt.*;

import java.awt.event.*;

import javax.swing.*;
 
public class Calculator {
	int num1=0;
	
	int num2=0;
	
	int k=0;		//区分num1和num2
	
	char ch=0;		//运算符
	
	String result;	//运算结果
	
	JFrame frame=new JFrame("Calculator");  
	
	JTextField result_TextField = new JTextField(result, 30);	//设计文本框
	
	//添加按钮
	
	JButton clear_botton = new JButton("clear");
	
    JButton button0 = new JButton("0");

    JButton button1 = new JButton("1");

    JButton button2 = new JButton("2");

    JButton button3 = new JButton("3");

    JButton button4 = new JButton("4");

    JButton button5 = new JButton("5");

    JButton button6 = new JButton("6");

    JButton button7 = new JButton("7");

    JButton button8 = new JButton("8");

    JButton button9 = new JButton("9");
    
    JButton button_jia = new JButton("+");

    JButton button_jian = new JButton("-");

    JButton button_cheng = new JButton("*");

    JButton button_chu = new JButton("/");

    JButton button_dy = new JButton("=");
    
    public Calculator() {
    	
    	result_TextField.setHorizontalAlignment(JTextField.RIGHT);
    	
    	JPanel f = new JPanel();
    	
    	f.setLayout(new GridLayout(4, 4, 8, 8));
    	
    	//按钮界面显示
    	
    	f.add(button7);

        f.add(button8);

        f.add(button9);

        f.add(button_chu);

        f.add(button4);

        f.add(button5);

        f.add(button6);

        f.add(button_cheng);

        f.add(button1);

        f.add(button2);

        f.add(button3);

        f.add(button_jian);

        f.add(button0);
        
        f.add(clear_botton);

        f.add(button_dy);

        f.add(button_jia);
    	
        f.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));
        
        JPanel f2 = new JPanel();

        f2.setLayout(new BorderLayout());

        f2.add(result_TextField, BorderLayout.WEST);
        
        // 设置主窗口出现在屏幕上的位置

        frame.setLocation(400, 200); 
        
        // 设置窗体不能调大小
 
        frame.setResizable(false); 

        frame.getContentPane().setLayout(new BorderLayout());

        frame.getContentPane().add(f2, BorderLayout.NORTH);

        frame.getContentPane().add(f, BorderLayout.CENTER);
        
        frame.pack();

        frame.setVisible(true);
 
        // 数字键
        
        class Listener implements ActionListener {

            public void actionPerformed(ActionEvent e) {

                String s1 = ((JButton) e.getSource()).getText();

                int i = Integer.valueOf(s1).intValue();
                if(k==0)
                {
                	num1=i;
                	k++;
                }
                else {
                	num2=i;
                }
                result_TextField.setText(s1);
            }
           }
        
     // 输入的运算符号的处理
        
        class Listener_signal implements ActionListener {

            public void actionPerformed(ActionEvent e) {

                String s2 = ((JButton) e.getSource()).getText();
                
                ch=s2.charAt(0);
                
                result_TextField.setText(s2);
            }
        }
        
        // 清除键的逻辑
        
        class Listener_clear implements ActionListener {
 
            public void actionPerformed(ActionEvent e) {

            	result_TextField.setText(result);
            }
        }
        
        // 等于键的逻辑
        
        class Listener_dy implements ActionListener {

            public void actionPerformed(ActionEvent e) {
            	  cal();
            	  k=0;
            }
        }
        // 监听数字键

        Listener jt = new Listener();

        // 监听符号键

        Listener_signal jt_signal = new Listener_signal();

        // 监听清除键

        Listener_clear jt_c = new Listener_clear(); 
        
        // 监听等于键
        Listener_dy jt_dy = new Listener_dy();


        button7.addActionListener(jt);

        button8.addActionListener(jt);

        button9.addActionListener(jt);

        button_chu.addActionListener(jt_signal);

        button4.addActionListener(jt);

        button5.addActionListener(jt);

        button6.addActionListener(jt);

        button_cheng.addActionListener(jt_signal);

        button1.addActionListener(jt);

        button2.addActionListener(jt);

        button3.addActionListener(jt);

        button_jian.addActionListener(jt_signal);

        button0.addActionListener(jt);

        button_dy.addActionListener(jt_dy);

        button_jia.addActionListener(jt_signal); 
        
        clear_botton.addActionListener(jt_c);
        
        // 窗体关闭事件
        
        frame.addWindowListener(new WindowAdapter() {

            public void windowClosing(WindowEvent e) {

                System.exit(0);

            }

        });
    }
    
    //计算函数
    public void cal() { 
    	
    	int result1=0;
    	
    	switch(ch) {
    		case '+':result1=num1+num2;break;
    		
    		case '-':result1=num1-num2;break;
    		
    		case '*':result1=num1*num2;break;
    		
    		case '/':result1=num1/num2;break; 
    	}
    		result =String.valueOf(result1);		//把int转化为string
            
            result_TextField.setText(result); 		
    }
     
	

public static void main(String[] args) {

    Calculator cal = new Calculator();
}
}