#pragma once
#include <iostream>
#include <msclr\marshal_cppstd.h> 
#include "Address.h"


namespace OOP_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Address* obj;
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			obj = new Address();
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
	private: System::Windows::Forms::Label^  Username_lb;
	private: System::Windows::Forms::TextBox^  username_tb;
	private: System::Windows::Forms::Label^  Password_lb;
	private: System::Windows::Forms::TextBox^  Password_tb;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  Login_b;
	private: System::Windows::Forms::Button^  Clear_b;




	protected:

	protected:










	protected:

	protected:





















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Username_lb = (gcnew System::Windows::Forms::Label());
			this->username_tb = (gcnew System::Windows::Forms::TextBox());
			this->Password_lb = (gcnew System::Windows::Forms::Label());
			this->Password_tb = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Login_b = (gcnew System::Windows::Forms::Button());
			this->Clear_b = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Username_lb
			// 
			this->Username_lb->AutoSize = true;
			this->Username_lb->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username_lb->Location = System::Drawing::Point(64, 233);
			this->Username_lb->Name = L"Username_lb";
			this->Username_lb->Size = System::Drawing::Size(167, 40);
			this->Username_lb->TabIndex = 1;
			this->Username_lb->Text = L"Username";
			// 
			// username_tb
			// 
			this->username_tb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->username_tb->Font = (gcnew System::Drawing::Font(L"Rockwell", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username_tb->Location = System::Drawing::Point(65, 286);
			this->username_tb->Name = L"username_tb";
			this->username_tb->Size = System::Drawing::Size(409, 31);
			this->username_tb->TabIndex = 2;
			// 
			// Password_lb
			// 
			this->Password_lb->AutoSize = true;
			this->Password_lb->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password_lb->Location = System::Drawing::Point(64, 352);
			this->Password_lb->Name = L"Password_lb";
			this->Password_lb->Size = System::Drawing::Size(156, 40);
			this->Password_lb->TabIndex = 3;
			this->Password_lb->Text = L"Password";
			// 
			// Password_tb
			// 
			this->Password_tb->Font = (gcnew System::Drawing::Font(L"Rockwell", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password_tb->Location = System::Drawing::Point(65, 408);
			this->Password_tb->Name = L"Password_tb";
			this->Password_tb->Size = System::Drawing::Size(409, 31);
			this->Password_tb->TabIndex = 4;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.23339F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.76661F)));
			this->tableLayoutPanel1->Controls->Add(this->Login_b, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->Clear_b, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(38, 528);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(589, 77);
			this->tableLayoutPanel1->TabIndex = 5;
			// 
			// Login_b
			// 
			this->Login_b->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Login_b->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Login_b->Font = (gcnew System::Drawing::Font(L"Tahoma", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_b->Location = System::Drawing::Point(5, 5);
			this->Login_b->Name = L"Login_b";
			this->Login_b->Size = System::Drawing::Size(281, 67);
			this->Login_b->TabIndex = 0;
			this->Login_b->Text = L"LOGIN";
			this->Login_b->UseVisualStyleBackColor = false;
			this->Login_b->Click += gcnew System::EventHandler(this, &MyForm::Login_b_Click);
			// 
			// Clear_b
			// 
			this->Clear_b->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Clear_b->Font = (gcnew System::Drawing::Font(L"Tahoma", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clear_b->Location = System::Drawing::Point(294, 5);
			this->Clear_b->Name = L"Clear_b";
			this->Clear_b->Size = System::Drawing::Size(288, 67);
			this->Clear_b->TabIndex = 1;
			this->Clear_b->Text = L"CLEAR";
			this->Clear_b->UseVisualStyleBackColor = true;
			this->Clear_b->Click += gcnew System::EventHandler(this, &MyForm::Clear_b_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(665, 627);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->Password_tb);
			this->Controls->Add(this->Password_lb);
			this->Controls->Add(this->username_tb);
			this->Controls->Add(this->Username_lb);
			this->MaximumSize = System::Drawing::Size(687, 683);
			this->MinimumSize = System::Drawing::Size(687, 683);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Clear_b_Click(System::Object^  sender, System::EventArgs^  e) {
		username_tb->Clear();
		Password_tb->Clear();
	}
private: System::Void Login_b_Click(System::Object^ sender, System::EventArgs^ e) {
	if (username_tb->Text == "Rudhan" && Password_tb->Text == "12345") {
		MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else if (String::IsNullOrEmpty(username_tb->Text) || String::IsNullOrEmpty(Password_tb->Text)) {
		MessageBox::Show("Username and password cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


};

}