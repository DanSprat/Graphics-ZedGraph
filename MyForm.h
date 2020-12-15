#pragma once
#include <math.h>
#include "numerical_methods.h"
#include "numerical_methods_lab2.h"
#include <string>
namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

  // Table





	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;


	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RadioButton^ TestRadioButton;
	private: System::Windows::Forms::RadioButton^ MainRadioButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumberOfColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ UandDouble;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SubVandSome;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;




	private: ZedGraph::ZedGraphControl^ zedGraphControl1;
	private: ZedGraph::ZedGraphControl^ zedGraphControl2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: ZedGraph::ZedGraphControl^ zedGraphControl3;































	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NumberOfColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->UandDouble = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SubVandSome = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->TestRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->MainRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl3 = (gcnew ZedGraph::ZedGraphControl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(646, 398);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->NumberOfColumn,
					this->X, this->V, this->UandDouble, this->SubVandSome
			});
			this->dataGridView1->Location = System::Drawing::Point(568, 52);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(297, 327);
			this->dataGridView1->TabIndex = 2;
			// 
			// NumberOfColumn
			// 
			this->NumberOfColumn->HeaderText = L"№ узла";
			this->NumberOfColumn->Name = L"NumberOfColumn";
			this->NumberOfColumn->ReadOnly = true;
			// 
			// X
			// 
			this->X->HeaderText = L"X";
			this->X->Name = L"X";
			this->X->ReadOnly = true;
			this->X->Width = 50;
			// 
			// V
			// 
			this->V->HeaderText = L"V ( x )";
			this->V->Name = L"V";
			this->V->ReadOnly = true;
			// 
			// UandDouble
			// 
			this->UandDouble->HeaderText = L"U ( x )";
			this->UandDouble->Name = L"UandDouble";
			this->UandDouble->ReadOnly = true;
			// 
			// SubVandSome
			// 
			this->SubVandSome->HeaderText = L"U ( x ) - V ( x )";
			this->SubVandSome->Name = L"SubVandSome";
			this->SubVandSome->ReadOnly = true;
			this->SubVandSome->Width = 124;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(54, 434);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Число разбиений";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(156, 431);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(56, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"10";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(306, 431);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(124, 20);
			this->textBox5->TabIndex = 11;
			this->textBox5->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(233, 434);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"max | Ui - Vi |";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// TestRadioButton
			// 
			this->TestRadioButton->AutoSize = true;
			this->TestRadioButton->Checked = true;
			this->TestRadioButton->Location = System::Drawing::Point(57, 398);
			this->TestRadioButton->Name = L"TestRadioButton";
			this->TestRadioButton->Size = System::Drawing::Size(111, 17);
			this->TestRadioButton->TabIndex = 14;
			this->TestRadioButton->TabStop = true;
			this->TestRadioButton->Text = L"Тестовая задача";
			this->TestRadioButton->UseVisualStyleBackColor = true;
			// 
			// MainRadioButton
			// 
			this->MainRadioButton->AutoSize = true;
			this->MainRadioButton->Location = System::Drawing::Point(187, 398);
			this->MainRadioButton->Name = L"MainRadioButton";
			this->MainRadioButton->Size = System::Drawing::Size(113, 17);
			this->MainRadioButton->TabIndex = 15;
			this->MainRadioButton->Text = L"Основная задача";
			this->MainRadioButton->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(288, 458);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(12, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"x";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(306, 455);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(124, 20);
			this->textBox2->TabIndex = 17;
			this->textBox2->Text = L"0";
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(-4, -5);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(501, 327);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(39, 31);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(502, 348);
			this->tabControl1->TabIndex = 18;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->zedGraphControl1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(494, 322);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L" Решение";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &MyForm::tabPage1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->zedGraphControl3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(494, 322);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Погрешность";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl3
			// 
			this->zedGraphControl3->Location = System::Drawing::Point(-4, -5);
			this->zedGraphControl3->Name = L"zedGraphControl3";
			this->zedGraphControl3->ScrollGrace = 0;
			this->zedGraphControl3->ScrollMaxX = 0;
			this->zedGraphControl3->ScrollMaxY = 0;
			this->zedGraphControl3->ScrollMaxY2 = 0;
			this->zedGraphControl3->ScrollMinX = 0;
			this->zedGraphControl3->ScrollMinY = 0;
			this->zedGraphControl3->ScrollMinY2 = 0;
			this->zedGraphControl3->Size = System::Drawing::Size(501, 327);
			this->zedGraphControl3->TabIndex = 19;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(893, 498);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->MainRadioButton);
			this->Controls->Add(this->TestRadioButton);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		GraphPane^ panel = zedGraphControl1->GraphPane;
		GraphPane^ panel2 = zedGraphControl3->GraphPane;
		panel2->CurveList->Clear();
		panel->CurveList->Clear();
		PointPairList^ f3_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f1_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f2_list = gcnew ZedGraph::PointPairList();

		// Интервал, где есть данные
		double xmin = Convert::ToDouble(textBox1->Text);
		//double xmax = Convert::ToDouble(textBox2->Text);


		double xmin_limit = xmin - 0.1;
		double xmax_limit = 1 + 0.1;
/*
		double ymin_limit = -1.0;
		double ymax_limit = 100.0;
*/
		// Список точек
		int i = 0;
		dataGridView1->Rows->Clear();

		// Число разбиений
		int n = Convert::ToInt64(textBox1->Text);
		String^ text();
		if (TestRadioButton->Checked) {
			TResults res = tfunc(0, 1, n, PI_4, k1Test, k2Test, q1Test, q2Test, f1Test, f2Test);
			TResults res2 = analyticalRes(u1, u2, PI_4, n);
			double max = 0;
			double max_x = 0;
			for (size_t i = 0; i < res.res_vec.size(); i++) {
				f1_list->Add(res.res_vec[i].first, res.res_vec[i].second);
				f2_list->Add(res2.res_vec[i].first, res2.res_vec[i].second);
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = i;
				dataGridView1->Rows[i]->Cells[1]->Value = res.res_vec[i].first;
				dataGridView1->Rows[i]->Cells[2]->Value = res.res_vec[i].second;
				dataGridView1->Rows[i]->Cells[3]->Value = res2.res_vec[i].second;
				dataGridView1->Rows[i]->Cells[4]->Value = (res2.res_vec[i].second- res.res_vec[i].second);
				double sub = (res2.res_vec[i].second - res.res_vec[i].second);
				f3_list->Add(res.res_vec[i].first, sub);
				if (abs(sub > max)) {
					max = abs(sub);
					max_x = res.res_vec[i].first;
				}
			}
			textBox5->Text = Convert::ToString(max);
			textBox2->Text = Convert::ToString(max_x);
		}
		else {
			double sub;
			TResults res = tfunc(0, 1, n, PI_4, k1, k2, q1, q2,f1,f2);
			TResults res2h = tfunc(0, 1, 2*n, PI_4, k1, k2, q1, q2, f1, f2);
			UandDouble->HeaderText = "V2 ( x )";
			SubVandSome->HeaderText = "V2 ( x ) - V ( x )";
			double max = 0;
			double max_x = 0;
			for (size_t i = 0; i < res.res_vec.size(); i++) {
				sub = (res.res_vec[i].second - res2h.res_vec[2 * i].second);
				f3_list->Add(res.res_vec[i].first, sub);
				if (abs(sub) > max) {
					max = abs(sub);
					max_x = res.res_vec[i].first;
				}
				f1_list->Add(res.res_vec[i].first, res.res_vec[i].second);
				if (i != 0) 
					f2_list->Add(res2h.res_vec[2 * i - 1].first, res2h.res_vec[2 * i - 1].second);

				f2_list->Add(res2h.res_vec[2*i].first, res2h.res_vec[2*i].second);
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = i;
				dataGridView1->Rows[i]->Cells[1]->Value = res.res_vec[i].first;
				dataGridView1->Rows[i]->Cells[2]->Value = res.res_vec[i].second;
				dataGridView1->Rows[i]->Cells[3]->Value = res2h.res_vec[2*i].second;
				dataGridView1->Rows[i]->Cells[4]->Value = sub;
			}
			MessageBox::Show("Для решения задачи использована равноверная сетка с числом разбиений n = " + n + "; задача должна быть решена с точностью e = 0.5.10^-6; задача решена с точностью e2 ="+max+"; максимальная разность численных решений наблюдается в точке x = " + max_x);
			textBox5->Text = Convert::ToString(max);
			textBox2->Text = Convert::ToString(max_x);
		}
		
		LineItem^ Curve3 = panel2->AddCurve("V ( x )", f3_list, Color::Red, SymbolType::None);
		LineItem^ Curve1 = panel->AddCurve("V ( x )", f1_list, Color::Red, SymbolType::None);
		LineItem^ Curve2 = panel->AddCurve("V2 ( x )", f2_list, Color::Blue, SymbolType::None);
		


		// Устанавливаем интересующий нас интервал по оси X
		panel->XAxis->Scale->Min = 0;
		panel->XAxis->Scale->Max =1;
/*
		// Устанавливаем интересующий нас интервал по оси Y
		panel->YAxis->Scale->Min = ymin_limit;
		panel->YAxis->Scale->Max = ymax_limit;
*/
		// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
		// В противном случае на рисунке будет показана только часть графика, 
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();

		zedGraphControl3->AxisChange();
		// Обновляем график
		zedGraphControl3->Invalidate();

	}
	private: System::Void tabPage_Clicked(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
