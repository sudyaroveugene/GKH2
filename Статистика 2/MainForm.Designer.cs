/*
 * Создано в SharpDevelop.
 * Пользователь: Алексей
 * Дата: 06.07.2019
 * Время: 19:37
 * 
 * Для изменения этого шаблона используйте меню "Инструменты | Параметры | Кодирование | Стандартные заголовки".
 */
namespace Статистика_2
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private System.Windows.Forms.Button GetStartButton;
		private System.Windows.Forms.ComboBox GroupSelector;
		private System.Windows.Forms.ComboBox PeriodStatistics;
		private System.Windows.Forms.PictureBox kartabox;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
			this.GetStartButton = new System.Windows.Forms.Button();
			this.GroupSelector = new System.Windows.Forms.ComboBox();
			this.PeriodStatistics = new System.Windows.Forms.ComboBox();
			this.kartabox = new System.Windows.Forms.PictureBox();
			((System.ComponentModel.ISupportInitialize)(this.kartabox)).BeginInit();
			this.SuspendLayout();
			// 
			// GetStartButton
			// 
			this.GetStartButton.Enabled = false;
			this.GetStartButton.Location = new System.Drawing.Point(761, 70);
			this.GetStartButton.Name = "GetStartButton";
			this.GetStartButton.Size = new System.Drawing.Size(137, 23);
			this.GetStartButton.TabIndex = 1;
			this.GetStartButton.Text = "Получить данные";
			this.GetStartButton.UseVisualStyleBackColor = true;
			this.GetStartButton.Click += new System.EventHandler(this.GetStartButtonClick);
			// 
			// GroupSelector
			// 
			this.GroupSelector.FormattingEnabled = true;
			this.GroupSelector.Location = new System.Drawing.Point(667, 16);
			this.GroupSelector.Name = "GroupSelector";
			this.GroupSelector.Size = new System.Drawing.Size(231, 21);
			this.GroupSelector.TabIndex = 2;
			this.GroupSelector.SelectedIndexChanged += new System.EventHandler(this.GroupSelectorSelectedIndexChanged);
			// 
			// PeriodStatistics
			// 
			this.PeriodStatistics.Enabled = false;
			this.PeriodStatistics.FormattingEnabled = true;
			this.PeriodStatistics.Location = new System.Drawing.Point(722, 43);
			this.PeriodStatistics.Name = "PeriodStatistics";
			this.PeriodStatistics.Size = new System.Drawing.Size(176, 21);
			this.PeriodStatistics.TabIndex = 3;
			this.PeriodStatistics.SelectedIndexChanged += new System.EventHandler(this.PeriodStatisticsSelectedIndexChanged);
			// 
			// kartabox
			// 
			this.kartabox.Image = ((System.Drawing.Image)(resources.GetObject("kartabox.Image")));
			this.kartabox.InitialImage = ((System.Drawing.Image)(resources.GetObject("kartabox.InitialImage")));
			this.kartabox.Location = new System.Drawing.Point(23, 18);
			this.kartabox.Name = "kartabox";
			this.kartabox.Size = new System.Drawing.Size(638, 291);
			this.kartabox.TabIndex = 4;
			this.kartabox.TabStop = false;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(925, 498);
			this.Controls.Add(this.kartabox);
			this.Controls.Add(this.PeriodStatistics);
			this.Controls.Add(this.GroupSelector);
			this.Controls.Add(this.GetStartButton);
			this.Name = "MainForm";
			this.Text = "Статистика 2";
			this.Load += new System.EventHandler(this.MainFormLoad);
			((System.ComponentModel.ISupportInitialize)(this.kartabox)).EndInit();
			this.ResumeLayout(false);

		}
	}
}
