package gui;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.BorderLayout;

import javax.swing.BorderFactory;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JInternalFrame;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import com.jgoodies.forms.factories.DefaultComponentFactory;

import javax.swing.JButton;

import java.awt.Color;
import java.awt.Component;
import java.awt.ComponentOrientation;
import java.awt.Font;
import java.awt.FlowLayout;
import java.io.IOException;

import javax.swing.BoxLayout;
import javax.swing.JTextPane;

import tcp.TCP;

public class GUI {

	private JFrame frame;
	private JPanel actualP;
	public TCP tcp;
	private SensorsControlPanel sP;
	private LedsControlPanel lP;

	/**
	 * @return the frame
	 */
	public JFrame getFrame() {
		return frame;
	}

	/**
	 * @param frame the frame to set
	 */
	public void setFrame(JFrame frame) {
		this.frame = frame;
	}	


	/**
	 * Create the application.
	 * @throws UnsupportedLookAndFeelException 
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 * @throws ClassNotFoundException 
	 */
	public GUI() throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		initialize();
	}

	public void setTCP(TCP tcp){
		this.tcp = tcp;
	}
	/**
	 * Initialize the contents of the frame.
	 * @throws UnsupportedLookAndFeelException 
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 * @throws ClassNotFoundException 
	 */
	private void initialize() throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		setFrame(new JFrame());
		getFrame().setResizable(false);
		getFrame().setBounds(100, 100, 800, 500);
		getFrame().setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		getFrame().getContentPane().setLayout(new BorderLayout(0, 0));
		actualP = new MenuPanel(this);
		getFrame().getContentPane().add(actualP, BorderLayout.CENTER);
	}
	

	/******************************************************
	 * 
	 * JPanel caricati Runtime
	 * 
	 * 
	 */

	
	public void showMenu() throws IOException{
		getFrame().remove(actualP);
		actualP = new MenuPanel(this);
		getFrame().getContentPane().add(actualP, BorderLayout.CENTER);
		refresh();
	}
	
	public void switchToLedsControl() throws IOException{
		getFrame().remove(actualP);
		actualP = new LedsControlPanel(this);
		lP = (LedsControlPanel) actualP;
		getFrame().getContentPane().add(actualP, BorderLayout.CENTER);
		refresh();
	}
	
	public void switchToSensorsControl() throws IOException{
		getFrame().remove(actualP);
		actualP = new SensorsControlPanel(this);
		sP = (SensorsControlPanel) actualP;
		getFrame().getContentPane().add(actualP, BorderLayout.CENTER);
		refresh();
	}

	private void refresh(){
		getFrame().validate();
		getFrame().repaint();
	}

	
	/******************************************************
	 * 
	 * Metodi per chiamare operazioni esterne alla GUI
	 * [OUTPUT]
	 * 
	 */
	
	public void ledPowerAction(int led) throws IOException{
		tcp.sendLedPowerAction(led);
	}
	
	public void changeDelay(int delay) throws IOException{
		tcp.sendNewDelay(delay);
	}
	
	public void changeMaxTemp(int temp) throws IOException{
		tcp.sendNewMaxTemp(temp);
	}
	
	public void setAlarmTempAction(boolean check) throws IOException{
		tcp.sendNewAlarmTemp(check);
	}
	
	public void setAlarmLightAction(boolean check) throws IOException{
		tcp.sendNewAlarmLight(check);
	}
	
	public void setAlarmPresenceAction(boolean check) throws IOException{
		tcp.sendNewAlarmPresence(check);
	}

	
	/******************************************************
	 * 
	 * Metodi per chiamare operazioni interne alla GUI
	 * [INPUT]
	 */
	
	public void setLedsGUI(String object, String object2, String object3, String object4, String object5, String object6){
		lP.txtOff.setText(object);
		lP.txtOff_1.setText(object2);
		lP.txtOff_2.setText(object3);
		lP.txtOff_3.setText(object4);
		lP.txtOff_4.setText(object5);
		lP.txtOff_5.setText(object6);
	}

	public void setLedGUI(int led, String state){
		switch(led){
			case 1:
				lP.txtOff.setText(state);
				break;
			case 2:
				lP.txtOff_1.setText(state);
				break;
			case 3:
				lP.txtOff_2.setText(state);
				break;
			case 4:
				lP.txtOff_3.setText(state);
				break;
			case 5:
				lP.txtOff_4.setText(state);
				break;
			case 6:
				lP.txtOff_5.setText(state);
				break;
		}
	}

	public void setSensorsGUI(String object, String object2, String object3, String object4, String object5, String object6, String object7){
		sP.textField.setText(object);
		sP.textField_1.setText(object2);
		sP.textField_2.setText(object3);
		sP.textField_3.setText(object6);
		sP.textField_4.setText(object5);
		sP.textField_5.setText(object4);
		sP.textField_6.setText(object7);
	}

	public void changeDelayFromExt(long delay){
		sP.slider.setValue((int) delay);
	}
	
	public void changeMaxTempFromExt(long temp){
		sP.spinner.setValue(temp);		
	}
	
	public void setAlarmTempActionFromExt(){
		sP.chckbxNewCheckBox.setSelected(!sP.chckbxNewCheckBox.isSelected());
	}
	
	public void setAlarmLightActionFromExt(){
		sP.chckbxNewCheckBox_1.setSelected(!sP.chckbxNewCheckBox_1.isSelected());
	}
	
	public void setAlarmPresenceActionFromExt(){
		sP.chckbxNewCheckBox_2.setSelected(!sP.chckbxNewCheckBox_2.isSelected());		
	}
}
