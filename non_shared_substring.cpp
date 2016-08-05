//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//struct Node
//{
//	vector<Node*> nextNodes;
//	vector<pair<int, int> > edges;
//	bool stringOne;
//	bool stringTwo;
//	Node()
//	{
//		stringOne = false;
//		stringTwo = false;
//	}
//};
//
//int getCommonStringLength(const string& text, int startPos1, int startPos2,
//		int string1Len)
//{
//	int sameCharNum = 0;
//	while (text[startPos1 + sameCharNum] == text[startPos2 + sameCharNum])
//	{
//		sameCharNum++;
//		if (sameCharNum == string1Len || startPos2 + sameCharNum == text.size())
//		{
//			break;
//		}
//	}
//	return sameCharNum;
//}
//
//bool checkSymbol(const string& text, char symbol)
//{
//	for (int i = 0; i < text.size(); i++)
//	{
//		if (text[i] == symbol)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//void updateTree(Node* root, const string& text, int subStringIdx, string& tempResult, const int textOneLen)
//{
//	bool containPound = checkSymbol(text.substr(subStringIdx), '#');
//	bool isStringOne = containPound && text[subStringIdx] != '#';
//	bool isStringTwo = !containPound;
//	if (subStringIdx >= text.size())
//	{
//		return;
//	}
//	for (int i = 0; i < root->nextNodes.size(); i++)
//	{
//		int startingPos = root->edges[i].first;
//		int commonStrLen = getCommonStringLength(text, startingPos,
//				subStringIdx, root->edges[i].second);
//		if (commonStrLen > 0 && commonStrLen < root->edges[i].second)
//		{
//			cout<<"1"<<endl;
//			Node* oldNode = root->nextNodes[i];
//			Node* newNode = new Node;
//			if (isStringOne)
//			{
//				newNode->stringOne = true;
//			}
//			else if (isStringTwo)
//			{
//				newNode->stringTwo = true;
//				if (oldNode->stringOne)
//				{
//					if(text[subStringIdx + commonStrLen + 1] != '$')
//					{
//						tempResult += text.substr(subStringIdx, commonStrLen + 1);
//					}
//					else
//					{
//						tempResult += text.substr(subStringIdx, commonStrLen);
//					}
//
//				}
//			}
//			pair<int, int> partOldEdge(startingPos + commonStrLen,
//					root->edges[i].second - commonStrLen);
//			pair<int, int> newEdge(subStringIdx + commonStrLen,
//					text.size() - subStringIdx - commonStrLen);
//			Node* middle = new Node;
//			if (isStringOne || oldNode->stringOne)
//			{
//				middle->stringOne = true;
//			}
//			if (isStringTwo || oldNode->stringTwo)
//			{
//				middle->stringTwo = true;
//			}
//			middle->nextNodes.push_back(oldNode);
//			middle->nextNodes.push_back(newNode);
//			middle->edges.push_back(partOldEdge);
//			middle->edges.push_back(newEdge);
//			root->nextNodes[i] = middle;
//			root->edges[i].second = commonStrLen;
//			return;
//		}
//		else if (commonStrLen == root->edges[i].second)
//		{
//			cout<<"2"<<endl;
//			Node* nextNode = root->nextNodes[i];
//			if (isStringOne)
//			{
//				nextNode->stringOne = true;
//			}
//			else if (isStringTwo)
//			{
//				nextNode->stringTwo = true;
//				if (nextNode->stringOne)
//				{
//					tempResult += text.substr(subStringIdx, commonStrLen);
//				}
//			}
//			updateTree(nextNode, text, subStringIdx + commonStrLen, tempResult);
//			return;
//		}
//		else if (commonStrLen == 0 && i == root->nextNodes.size() - 1)
//		{
//			cout<<"3"<<endl;
//			Node* newNode = new Node;
//			if (isStringOne)
//			{
//				newNode->stringOne = true;
//			}
//			else if (isStringTwo)
//			{
//				newNode->stringTwo = true;
//				cout<<"33 "<<tempResult<<endl;
//				int j = i;
//				while(text[root->edges[j].first] == '#')
//				{
//					j--;
//				}
//				if(text[subStringIdx] != '$' || tempResult.size() > 0)
//				{
//					tempResult += text[root->edges[j].first];
//				}
//
//
//			}
//			pair<int, int> newEdge(subStringIdx, text.size() - subStringIdx);
//			root->nextNodes.push_back(newNode);
//			root->edges.push_back(newEdge);
//			pair<int, int> test = root->edges[0];
//			return;
//		}
//	}
//	cout<<"4"<<endl;
//	Node* nextNode = new Node;
//	if (isStringOne)
//	{
//		nextNode->stringOne = true;
//	}
//	else if (isStringTwo)
//	{
//		nextNode->stringTwo = true;
//	}
//	root->nextNodes.push_back(nextNode);
//
//	pair<int, int> stringIdx(subStringIdx, text.size() - subStringIdx);
//	root->edges.push_back(stringIdx);
//	return;
//}
//
//void getShortestCommonString(const Node* root, int nodeIdx, const string& text,
//		string comString, string& result)
//{
//	if (text[root->edges[nodeIdx].first] != '#'
//			&& text[root->edges[nodeIdx].first] != '$')
//	{
//		Node* nextNode = root->nextNodes[nodeIdx];
//		if (nextNode->stringOne)
//		{
//			bool sameFlag = nextNode->stringOne && nextNode->stringTwo;
//			if (sameFlag)
//			{
//				string tempString = comString
//						+ text.substr(root->edges[nodeIdx].first,
//								root->edges[nodeIdx].second);
//				for (int i = 0; i < nextNode->nextNodes.size(); i++)
//				{
//					getShortestCommonString(nextNode, i, text, tempString,
//							result);
//				}
//			}
//			else
//			{
//				string tempString = comString
//						+ text[root->edges[nodeIdx].first];
//				if (tempString.size() < result.size())
//				{
//					result = tempString;
//				}
//			}
//		}
//
//	}
//
//}
//
//string solve(string p, string q)
//{
////	string result = p;
////	string text;
////	text += p;
////	text += '#';
////	text += q;
////	text += '$';
//	string result = q;
//	string text;
//	text += q;
//	text += '#';
//	text += p;
//	text += '$';
//
//	Node* root = new Node;
//	string nullString;
//	cout<<"NUllString: "<< nullString<<endl;
//	for (int i = 0; i < text.size(); i++)
//	{
//		string tempResult;
//		cout<<"String:   "<<text.substr(i)<<endl;
//		updateTree(root, text, i, tempResult);
//		cout<<tempResult<<endl;
//		if (tempResult.size() < result.size() && tempResult.size() > 0)
//		{
//			result = tempResult;
//		}
////		if(tempResult.size() > nullString.size())
////		{
////			nullString = tempResult;
////			cout<<"NUllString: "<< nullString<<endl;
////		}
//	}
//
//	// string tempString;
//	// for (int i = 0; i < root->nextNodes.size(); i++)
//	// {
//	// 	getShortestCommonString(root, i, text, tempString, result);
//	// }
//
//	return result = nullString;
//}
//
//int main(void)
//{
//	string p;
//	cin >> p;
//	string q;
//	cin >> q;
//
//	string ans = solve(p, q);
//    cout<<"=============="<<endl;
//	cout << ans << endl;
//
//	return 0;
//}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
	vector<Node*> nextNodes;
	vector<pair<int, int> > edges;
	bool stringOne;
	bool stringTwo;
	Node()
	{
		stringOne = false;
		stringTwo = false;
	}
};

int getCommonStringLength(const string& text, int startPos1, int startPos2,
		int string1Len)
{
	int sameCharNum = 0;
	while (text[startPos1 + sameCharNum] == text[startPos2 + sameCharNum])
	{
		sameCharNum++;
		if (sameCharNum == string1Len || startPos2 + sameCharNum == text.size())
		{
			break;
		}
	}
	return sameCharNum;
}



void updateTree(Node* root, const string& text, int subStringIdx, const int textOneLen)
{
	bool isStringOne = subStringIdx < textOneLen;
	bool isStringTwo = subStringIdx > textOneLen;
	if (subStringIdx >= text.size())
	{
		return;
	}
	for (int i = 0; i < root->nextNodes.size(); i++)
	{
		int startingPos = root->edges[i].first;
		int commonStrLen = getCommonStringLength(text, startingPos,
				subStringIdx, root->edges[i].second);
		if (commonStrLen > 0 && commonStrLen < root->edges[i].second)
		{
			Node* oldNode = root->nextNodes[i];
			Node* newNode = new Node;
			if (isStringOne)
			{
				newNode->stringOne = true;
			}
			else if (isStringTwo)
			{
				newNode->stringTwo = true;
			}
			pair<int, int> partOldEdge(startingPos + commonStrLen,
					root->edges[i].second - commonStrLen);
			pair<int, int> newEdge(subStringIdx + commonStrLen,
					text.size() - subStringIdx - commonStrLen);
			Node* middle = new Node;
			if (isStringOne || oldNode->stringOne)
			{
				middle->stringOne = true;
			}
			if (isStringTwo || oldNode->stringTwo)
			{
				middle->stringTwo = true;
			}
			middle->nextNodes.push_back(oldNode);
			middle->nextNodes.push_back(newNode);
			middle->edges.push_back(partOldEdge);
			middle->edges.push_back(newEdge);
			root->nextNodes[i] = middle;
			root->edges[i].second = commonStrLen;
			return;
		}
		else if (commonStrLen == root->edges[i].second)
		{
			Node* nextNode = root->nextNodes[i];
			if (isStringOne)
			{
				nextNode->stringOne = true;
			}
			else if (isStringTwo)
			{
				nextNode->stringTwo = true;
			}
			updateTree(nextNode, text, subStringIdx + commonStrLen, textOneLen);
			return;
		}
		else if (commonStrLen == 0 && i == root->nextNodes.size() - 1)
		{
			Node* newNode = new Node;
			if (isStringOne)
			{
				newNode->stringOne = true;
			}
			else if (isStringTwo)
			{
				newNode->stringTwo = true;
			}
			pair<int, int> newEdge(subStringIdx, text.size() - subStringIdx);
			root->nextNodes.push_back(newNode);
			root->edges.push_back(newEdge);
			pair<int, int> test = root->edges[0];
			return;
		}
	}
	Node* nextNode = new Node;
	if (isStringOne)
	{
		nextNode->stringOne = true;
	}
	else if (isStringTwo)
	{
		nextNode->stringTwo = true;
	}
	root->nextNodes.push_back(nextNode);

	pair<int, int> stringIdx(subStringIdx, text.size() - subStringIdx);
	root->edges.push_back(stringIdx);
	return;
}

void getShortestCommonString(const Node* root, int nodeIdx, const string& text,
		string comString, string& result)
{
	if (text[root->edges[nodeIdx].first] != '#'
			&& text[root->edges[nodeIdx].first] != '$')
	{
		Node* nextNode = root->nextNodes[nodeIdx];
		if (nextNode->stringOne)
		{
			bool sameFlag = nextNode->stringOne && nextNode->stringTwo;
			if (sameFlag)
			{
				string tempString = comString
						+ text.substr(root->edges[nodeIdx].first,
								root->edges[nodeIdx].second);
				for (int i = 0; i < nextNode->nextNodes.size(); i++)
				{
					getShortestCommonString(nextNode, i, text, tempString,
							result);
				}
			}
			else
			{
				string tempString = comString
						+ text[root->edges[nodeIdx].first];
				if (tempString.size() < result.size())
				{
					result = tempString;
				}
			}
		}

	}

}

string solve(string p, string q)
{
	string result = p;
	string text;
	text += p;
	text += '#';
	text += q;
	text += '$';

	Node* root = new Node;
	for (int i = 0; i < text.size(); i++)
	{
		updateTree(root, text, i, p.size());
	}

	 string tempString;
	 for (int i = 0; i < root->nextNodes.size(); i++)
	 {
	 	getShortestCommonString(root, i, text, tempString, result);
	 }

	return result;
}

int main(void)
{
	string p;
	cin >> p;
	string q;
	cin >> q;

	string ans = solve(p, q);

	cout << ans << endl;

	return 0;
}
