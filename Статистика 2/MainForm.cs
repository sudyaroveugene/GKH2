/*
 * Создано в SharpDevelop.
 * Пользователь: Алексей
 * Дата: 06.07.2019
 * Время: 19:37
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Статистика_2
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		void GetStartButtonClick(object sender, EventArgs e)
		{
			MainForm.ActiveForm.Refresh();
			int[] Hour =  new int[24];
			for (int i = 0; i < Hour.Length; i++) {
				Hour[i] = i;
			}
			string[]  DayName = new string[]{"пн","вт", "ср", "чт", "пт", "сб", "вс"};
			string[] Month = new string[]{"янв", "фев", "мрт", "чт", "пт", "сб", "вс"};
			
			float[] AquaMassive = new float[8760];
			Random AquaParam = new Random();
			
			
			
			// Заполнение массива данными
			for (int i = 0; i < AquaMassive.Length; i++) {
				
				for (int j = 0; j < 24; j++) {
					if (j < 4) {
						AquaMassive[i] = (float)AquaParam.Next(10, 20);
					}
					
					if (j > 3 & j < 8) {
						AquaMassive[i] = (float)AquaParam.Next(20, 30);	
					}
					if (j > 7 & j < 12) {
						AquaMassive[i] = (float)AquaParam.Next(60, 100);	
					}					
							
					if (j > 11 & j < 16) {
						AquaMassive[i] = (float)AquaParam.Next(50, 80);	
					}
					
					if (j > 15 & j < 20) {
						AquaMassive[i] = (float)AquaParam.Next(30, 70);	
					}
					if (j > 19 & j < 24) {
						AquaMassive[i] = (float)AquaParam.Next(10, 30);	
					}
					i += 1;
					if (i == AquaMassive.Length) {
						break;
					}
				}
			}
			
			// Получение массива усредненных значений по периодам
			//24 часа
			float[] Avg24 = new float[24];
			
			int oper = 0;
			for (int i = 0; i < 26; i++) {
				
				for (int L = 0; L < 24; L++) {
					Avg24[L] = AquaMassive[oper];
					oper++;
				}
				
			}

			
			
			
			Pen SetkaPen = new Pen(Color.Black, 1);
			Pen	GrafPen = new Pen(Color.Blue, 1);
			Pen ExtraPen = new Pen(Color.Red, 1);
			Point CoordPoint = new Point(20,450);
			
			Graphics G = CreateGraphics();
			Point[]	StaticCurve = getGraphik(AquaMassive, CoordPoint,24);
			Point[] ExtraCurve = getGraphik(Avg24, CoordPoint,24);
			
			float MaxMassiveElement = 0;
			for (int i = 0; i < StaticCurve.Length; i++) {
				if (AquaMassive[i] > MaxMassiveElement) {
					MaxMassiveElement = AquaMassive[i];
				}
			}
			
			G.DrawLines(GrafPen,StaticCurve);
			G.DrawLines(ExtraPen,ExtraCurve);
			
			// Сетка
			Point MaxX = new Point(CoordPoint.X + 25*StaticCurve.Length, CoordPoint.Y);
			Point MaxY = new Point(CoordPoint.X, CoordPoint.Y - (int)MaxMassiveElement);
			G.DrawLine(SetkaPen, CoordPoint, MaxX);
			G.DrawLine(SetkaPen, CoordPoint, MaxY);
			for (int i = 0; i < ExtraCurve.Length; i++) {
				G.DrawLine(SetkaPen,ExtraCurve[i].X, CoordPoint.Y, ExtraCurve[i].X, CoordPoint.Y + 10);


			}
	
		}

		
		public static Point[] getGraphik(float[] Massive, Point Coord0, int CountData)
		{
		
			Point[] CoordCurve = new Point[CountData];
			for (int i = 0; i < CountData; i++) {
				if (i == 0) {
					CoordCurve[i].X = Coord0.X;
					CoordCurve[i].Y = Coord0.Y - (int)Massive[i];
				} else {
					CoordCurve[i].X = CoordCurve[i - 1].X + 25;
					CoordCurve[i].Y = Coord0.Y - (int)Massive[i];
				}
			}
			return CoordCurve;
		}
		
		void MainFormLoad(object sender, EventArgs e)
		{
			
			
			string[] SelectList = new string[] {
				"Выберите интересующую категорию:",
				"Электроснабжение",
				"Водоснабжение",
				"Газоснабжение",
				"Водоотведение",
				"Вывоз мусора"
			};
			string[] PeriodList = new string[] {
				"Укажите период:",
				"24 часа"
			};
			
			 
			
			GroupSelector.Items.AddRange(SelectList);
			GroupSelector.SelectedIndex = 0;
			
			
			PeriodStatistics.Items.AddRange(PeriodList);
			PeriodStatistics.SelectedIndex = 0;
			
			
			
		}
		void GroupSelectorSelectedIndexChanged(object sender, EventArgs e)
		{
			if (GroupSelector.SelectedIndex != 0) {
				PeriodStatistics.Enabled = true;
			} else {
				PeriodStatistics.Enabled = false;
				GetStartButton.Enabled = false;
			}
		}
		void PeriodStatisticsSelectedIndexChanged(object sender, EventArgs e)
		{
			if (PeriodStatistics.Enabled == true & PeriodStatistics.SelectedIndex != 0 & GroupSelector.SelectedIndex != 0) {
				
				GetStartButton.Enabled = true;
			} else {
				GetStartButton.Enabled = false;
			}
		}

		
	}
}
