#pragma once

#include <msclr/marshal_cppstd.h>

namespace CompilerC {

	
	using namespace System::ComponentModel;
	using namespace System::Collections;

	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  filepath;
	private: System::Windows::Forms::DataGridView^  symboltable;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  symbol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  values;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TreeView^  ast;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  syntaxout;

	private: System::Windows::Forms::Button^  filepathbtn;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->filepath = (gcnew System::Windows::Forms::TextBox());
			this->symboltable = (gcnew System::Windows::Forms::DataGridView());
			this->symbol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->values = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ast = (gcnew System::Windows::Forms::TreeView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->syntaxout = (gcnew System::Windows::Forms::Label());
			this->filepathbtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->symboltable))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Fuchsia;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 37);
			this->label1->TabIndex = 0;
			this->label1->Text = L"C++ Compiler";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(12, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 30);
			this->label2->TabIndex = 1;
			this->label2->Text = L"File Path";
			// 
			// filepath
			// 
			this->filepath->BackColor = System::Drawing::Color::Gainsboro;
			this->filepath->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->filepath->Location = System::Drawing::Point(109, 73);
			this->filepath->Name = L"filepath";
			this->filepath->Size = System::Drawing::Size(291, 18);
			this->filepath->TabIndex = 2;
			this->filepath->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// symboltable
			// 
			this->symboltable->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->symboltable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->symboltable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->symbol, this->name,
					this->values
			});
			this->symboltable->Location = System::Drawing::Point(19, 174);
			this->symboltable->Name = L"symboltable";
			this->symboltable->Size = System::Drawing::Size(494, 299);
			this->symboltable->TabIndex = 3;
			// 
			// symbol
			// 
			this->symbol->HeaderText = L"Symbol";
			this->symbol->Name = L"symbol";
			this->symbol->Width = 150;
			// 
			// name
			// 
			this->name->HeaderText = L"Name";
			this->name->Name = L"name";
			this->name->Width = 150;
			// 
			// values
			// 
			this->values->HeaderText = L"Value";
			this->values->Name = L"values";
			this->values->Width = 150;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Fuchsia;
			this->label3->Location = System::Drawing::Point(12, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(144, 30);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Symbol Table";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Fuchsia;
			this->label4->Location = System::Drawing::Point(585, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(221, 30);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Abstract Symbol Tree";
			// 
			// ast
			// 
			this->ast->Location = System::Drawing::Point(590, 174);
			this->ast->Name = L"ast";
			this->ast->Size = System::Drawing::Size(387, 299);
			this->ast->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Fuchsia;
			this->label5->Location = System::Drawing::Point(14, 497);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(80, 30);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Syntax";
			// 
			// syntaxout
			// 
			this->syntaxout->AutoSize = true;
			this->syntaxout->BackColor = System::Drawing::Color::Transparent;
			this->syntaxout->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->syntaxout->ForeColor = System::Drawing::Color::Red;
			this->syntaxout->Location = System::Drawing::Point(14, 536);
			this->syntaxout->Name = L"syntaxout";
			this->syntaxout->Size = System::Drawing::Size(0, 25);
			this->syntaxout->TabIndex = 8;
			// 
			// filepathbtn
			// 
			this->filepathbtn->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->filepathbtn->Location = System::Drawing::Point(419, 66);
			this->filepathbtn->Name = L"filepathbtn";
			this->filepathbtn->Size = System::Drawing::Size(78, 31);
			this->filepathbtn->TabIndex = 9;
			this->filepathbtn->Text = L"Parse";
			this->filepathbtn->UseVisualStyleBackColor = false;
			this->filepathbtn->Click += gcnew System::EventHandler(this, &MyForm::filepathbtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 600);
			this->Controls->Add(this->filepathbtn);
			this->Controls->Add(this->syntaxout);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->ast);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->symboltable);
			this->Controls->Add(this->filepath);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->symboltable))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
		 


private: System::Void symboltableupdate() {
	int i = 0;
	Abdul_Ali_Token_Type* t;
	do {
		t = getrecord(i);
		System::String^ clrString = msclr::interop::marshal_as<System::String^>(t->Name_048);
		System::String^ clrString2 = msclr::interop::marshal_as<System::String^>(t->words);
		symboltable->Rows->Add(clrString, clrString2, t->Values_048);
		i++;
	} while (t->Token_048 != END);
}


private:
	void PushTreeNodeToTreeView(treenode* node, System::Windows::Forms::TreeNode^ treeNode, System::Windows::Forms::TreeView^ treeView)
	{
		if (node->name != "") {
			treeNode->Text = gcnew System::String(msclr::interop::marshal_as<System::String^>(node->name));
		}
		else if (node->name == "" || (node->value < 999999 && node->value >= 0)) {
			treeNode->Text = gcnew System::String(msclr::interop::marshal_as<System::String^>(std::to_string(node->value)));
		}

		if (node->leftchild != nullptr)
		{
			System::Windows::Forms::TreeNode^ leftChildNode = gcnew System::Windows::Forms::TreeNode();
			PushTreeNodeToTreeView(node->leftchild, leftChildNode, treeView);
			treeNode->Nodes->Add(leftChildNode);
		}

		if (node->middlechild != nullptr)
		{
			System::Windows::Forms::TreeNode^ middleChildNode = gcnew System::Windows::Forms::TreeNode();
			PushTreeNodeToTreeView(node->middlechild, middleChildNode, treeView);
			treeNode->Nodes->Add(middleChildNode);
		}

		if (node->rightchild != nullptr)
		{
			System::Windows::Forms::TreeNode^ rightChildNode = gcnew System::Windows::Forms::TreeNode();
			PushTreeNodeToTreeView(node->rightchild, rightChildNode, treeView);
			treeNode->Nodes->Add(rightChildNode);
		}

		if (node->sibling != nullptr && node->sibling->name != "" && node->sibling->value != -1)
		{
			System::Windows::Forms::TreeNode^ siblingNode = gcnew System::Windows::Forms::TreeNode();
			PushTreeNodeToTreeView(node->sibling, siblingNode, treeView);

			if (treeNode->Parent != nullptr)
			{
				treeNode->Parent->Nodes->Add(siblingNode);
			}
			else
			{
				treeView->Nodes->Add(siblingNode);
			}
		}
	}

	void UpdateTreeView(treenode* root)
	{
		// Clear the existing nodes in your TreeView control (ast)
		ast->Nodes->Clear();

		// Create a root System::Windows::Forms::TreeNode and push the root treenode and its children
		System::Windows::Forms::TreeNode^ rootNode = gcnew System::Windows::Forms::TreeNode();
		PushTreeNodeToTreeView(root, rootNode, ast);

		// Add the root System::Windows::Forms::TreeNode to the TreeView control
		ast->Nodes->Add(rootNode);

	}

private: System::Void filepathbtn_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string path;
	msclr::interop::marshal_context context;
	path = context.marshal_as<std::string>(filepath->Text);
	treenode* f = fileopener(path);
	if (parserstart()) {

		symboltableupdate();
		UpdateTreeView(f);
		syntaxout->ForeColor = System::Drawing::Color::Green;
		syntaxout->Text = "Syntax is Correct!";
	}
	else {
		syntaxout->Text = "Syntax is Incorrect!";
	}
}

};
}
