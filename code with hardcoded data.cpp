#include <iostream> 
#include <cstring>
#include <string>
using namespace std; 


const int MAX_NODES = 50; 
const int NO_CONNECTION = -1; 
const int INT_INFINITY = 1000000;  

  
class SocialNetworkGraph 
{ 
	
	private: 
	
	    int nodeIndex[MAX_NODES];  
	    string nodeTitles[MAX_NODES];
	    int adjacencyMatrix[MAX_NODES][MAX_NODES]; 
	
	  
	
	public: 
	
	    SocialNetworkGraph () 
		{ 
	        for (int i = 0; i < MAX_NODES; ++i) 
			{ 
	            nodeIndex[i] = -1; 
	            nodeTitles[i] = " ";
				 
	            for (int j = 0; j < MAX_NODES; ++j) 
				{ 
	                adjacencyMatrix[i][j] = NO_CONNECTION; 
	            } 
	        } 
	    } 
	
	    void addEdge(const string& source, const string& destination, int weight) 
		{ 
	
	        int sourceIndex = getNodeIndex(source); 
	        int destIndex = getNodeIndex(destination); 
	
	        adjacencyMatrix[sourceIndex][destIndex] = weight; 
	
	    } 
	
	    int getNodeIndex(const string& nodeName) 
		{ 
	        int index = -1; 
	        for (int i = 0; i < MAX_NODES; ++i) 
			{ 
	            if (nodeIndex[i] == -1) 
				{ 
	                nodeIndex[i] = i;
	                nodeTitles[i] = nodeName;
	                index = i;
	                break;
	            } 
	            else if (nodeName == nodeTitles[i]) 
				{ 
	                index = i;
	                break;
	            } 
	        } 
	        return index;
	    } 
	
	  
	    void dijkstra(const string& startNode, const string& endNode) 
		{ 
	
	        int startNodeIndex = getNodeIndex(startNode); 
	        int endNodeIndex = getNodeIndex(endNode); 
	
	        int distance[MAX_NODES]; 
	        int previousNode[MAX_NODES]; 
	        bool visited[MAX_NODES] = {false}; 

	        for (int i = 0; i < MAX_NODES; ++i) 
			{ 
	            distance[i] = INT_INFINITY;
	            previousNode[i] = -1; 
	        } 
	        
	        distance[startNodeIndex] = 0; 
	        
	        for (int count = 0; count < MAX_NODES; ++count) 
			{ 
	            int minDistance = INT_INFINITY; 
	            int minIndex = -1; 
	            
	            for (int v = 0; v < MAX_NODES; ++v) 
				{ 
	
	                if (!visited[v] && distance[v] < minDistance) 
					{ 
	                    minDistance = distance[v]; 
	                    minIndex = v; 
	                } 
	            } 
	
	            visited[minIndex] = true;  
	
	            for (int v = 0; v < MAX_NODES; ++v) 
				{ 
	
	                if (!visited[v] && adjacencyMatrix[minIndex][v] != NO_CONNECTION && 
	
	                    distance[minIndex] != INT_INFINITY && 
	
	                    distance[minIndex] + adjacencyMatrix[minIndex][v] < distance[v]) 
						{ 
		                    distance[v] = distance[minIndex] + adjacencyMatrix[minIndex][v]; 
		                    previousNode[v] = minIndex; 
	               	 	} 
	
	            } 

	            if (minIndex == endNodeIndex) 
				{ 
	                break; 
	            }
	        } 
	
	        printShortestPath(startNodeIndex, endNodeIndex, previousNode); 
	
	    } 
	
	  
	
	    void printShortestPath(int startNodeIndex, int endNodeIndex, const int previousNode[]) 
		{ 
	
	        int path[MAX_NODES]; 
	        int pathLength = 0; 
	
	  
	        for (int at = endNodeIndex; at != -1; at = previousNode[at]) 
			{ 
	            path[pathLength++] = at; 
	        } 
	
	        cout << "Shortest path from " << nodeTitles[startNodeIndex] << " to " << nodeTitles[endNodeIndex] << ": "; 
	
	        for (int i = pathLength - 1; i >= 0; --i) 
			{ 
	            cout << nodeTitles[path[i]]; 
	            if (i > 0) 
				{ 
	                cout << " -> "; 
	            } 
	        } 
	        cout << endl; 
	    } 

}; 

  

int main()  

{
	SocialNetworkGraph academicGraph; 
	    
	
	    academicGraph.addEdge("ABDUL SABOOR", "ABDUL HASEEB", 6); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "ABDULLAH EJAZ", 9); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "ABU SALEH", 6); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "BILAL HABIB", 10); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "FAHAD ALI", 5); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "HASEEB UR REHMAN", 8); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD HUZAIFA", 1); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "IBRAHIM ARSHAD", 1); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "IBRAHIM FAROOQ", 1); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "KAUNAIN HUSSAIN", 9); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "KAZIM ALI SHAH", 4); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MOHAMMAD OSMAN ABDULLAH", 6); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD ABDUL SABOOR", 7); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD MOHEEZ", 1); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD MUSTAFA", 9); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD SAFAAN UMAR", 9); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD SHAIEL", 5); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD USAMA UMER", 4); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "SHAHZAIB KHAKWANI", 4); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "TAHA AZMAT", 8); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "TALHA ASIF", 8); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "WASIF ALI", 5); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "ZAIN ULLAH UMAR", 4); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "JUNAID AHMED", 1); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "SARTAJ", 1); 
	
	    academicGraph.addEdge("ABDUL SABOOR", "MUHAMMAD ABDULLAH", 1); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "ABDUL HASEEB", 6); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "ABDUL SABOOR", 4); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "ABDULLAH EJAZ", 7); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "ABU SALEH", 3); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "ALISHA GHAYAS", 1); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "BILAL HABIB", 3); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "EMAN RIZWAN", 3); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "FAHAD ALI", 5); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "HASEEB UR REHMAN", 6); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD HUZAIFA", 6); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "IBRAHIM ARSHAD", 10); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "KAUNAIN HUSSAIN", 4); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "KAZIM ALI SHAH", 4); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MALAIKA JUNAID", 2); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MALAIKA SATTAR", 3); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MOHAMMAD OSMAN ABDULLAH", 9); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD ABDUL SABOOR", 5); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD MOHEEZ", 6); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD MUSTAFA", 8); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD SAFAAN UMAR", 9); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD SHAIEL", 7); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD USAMA UMER", 9); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUNIBA MANAAL", 6); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "RAMEEN JAMSHED", 3); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "SHAHZAIB KHAKWANI", 9); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "SHEEZA TANVEER", 8); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "SYEDA ALEEZA TAHIR", 5); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "TAHA AZMAT", 8); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "TALHA ASIF", 8); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "WASIF ALI", 8); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "ZAIN ULLAH UMAR", 6); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "ZANEB AKHTAR", 2); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "JUNAID AHMED", 7); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "SARTAJ", 6); 
	
	    academicGraph.addEdge("IBRAHIM FAROOQ", "MUHAMMAD ABDULLAH", 2); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "ABDULLAH EJAZ", 3); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "ALISHA GHAYAS", 7); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "IBRAHIM ARSHAD", 5); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "IBRAHIM FAROOQ", 6); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "KAZIM ALI SHAH", 8); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MALAIKA JUNAID", 8); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MALAIKA SATTAR", 8); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MOHAMMAD OSMAN ABDULLAH", 5); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MUHAMMAD ABDUL SABOOR", 9); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MUHAMMAD MUSTAFA", 6); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MUHAMMAD SAFAAN UMAR", 3); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MUHAMMAD USAMA UMER", 5); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "MUNIBA MANAAL", 7); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "RAMEEN JAMSHED", 8); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "SHEEZA TANVEER", 9); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "SYEDA ALEEZA TAHIR", 10); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "TAHA AZMAT", 8); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "TALHA ASIF", 8); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "ZANEB AKHTAR", 8); 
	
	    academicGraph.addEdge("EMAN RIZWAN", "JUNAID AHMED", 4); 
	
	   academicGraph.addEdge("KAZIM ALI SHAH", "ABU SALEH", 9); 
	
		academicGraph.addEdge("KAZIM ALI SHAH", "ALISHA GHAYAS", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "BILAL HABIB", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "EMAN RIZWAN", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "FAHAD ALI", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "HASEEB UR REHMAN", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "IBRAHIM ARSHAD", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "IBRAHIM FAROOQ", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "KAUNAIN HUSSAIN", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "KAZIM ALI SHAH", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MALAIKA JUNAID", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MALAIKA SATTAR", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MOHAMMAD OSMAN ABDULLAH", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MUHAMMAD ABDUL SABOOR", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MUHAMMAD MOHEEZ", 6); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MUHAMMAD MUSTAFA", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MUHAMMAD SAFAAN UMAR", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MUHAMMAD SHAIEL", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MUHAMMAD USAMA UMER", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "MUNIBA MANAAL", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "RAMEEN JAMSHED", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "SHAHZAIB KHAKWANI", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "SHEEZA TANVEER", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "SYEDA ALEEZA TAHIR", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "TAHA AZMAT", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "TALHA ASIF", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "WASIF ALI", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "ZAIN ULLAH UMAR", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "ZANEB AKHTAR", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "JUNAID AHMED", 9); 
		
		academicGraph.addEdge("KAZIM ALI SHAH", "SARTAJ", 9); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "ABDULLAH EJAZ", 2); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "ABU SALEH", 1); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "ALISHA GHAYAS", 6); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "EMAN RIZWAN", 10); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MUHAMMAD HUZAIFA", 1); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "IBRAHIM ARSHAD", 5); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "IBRAHIM FAROOQ", 5); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "KAZIM ALI SHAH", 10); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MALAIKA JUNAID", 9); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MALAIKA SATTAR", 8); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MOHAMMAD OSMAN ABDULLAH", 6); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MUHAMMAD ABDUL SABOOR", 10); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MUHAMMAD MUSTAFA", 9); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MUHAMMAD SAFAAN UMAR", 7); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MUHAMMAD USAMA UMER", 8); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "MUNIBA MANAAL", 8); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "RAMEEN JAMSHED", 8); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "SHEEZA TANVEER", 7); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "TAHA AZMAT", 10); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "TALHA ASIF", 10); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "WASIF ALI", 2); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "ZANEB AKHTAR", 8); 
	
	    academicGraph.addEdge("SYEDA ALEEZA TAHIR", "JUNAID AHMED", 2); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "ALISHA GHAYAS", 9); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "EMAN RIZWAN", 9); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "IBRAHIM ARSHAD", 2); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "IBRAHIM FAROOQ", 4); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "MALAIKA JUNAID", 9); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "MOHAMMAD OSMAN ABDULLAH", 6); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "MUHAMMAD ABDUL SABOOR", 5); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "MUHAMMAD MUSTAFA", 5); 
	
	    academicGraph.addEdge("MAL AIKA SATTAR", "MUHAMMAD SAFAAN UMAR", 6); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "MUHAMMAD USAMA UMER", 6); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "MUNIBA MANAAL", 8); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "RAMEEN JAMSHED", 8); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "SHEEZA TANVEER", 9); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "SYEDA ALEEZA TAHIR", 9); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "TAHA AZMAT", 5); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "TALHA ASIF", 5); 
	
	    academicGraph.addEdge("MALAIKA SATTAR", "ZANEB AKHTAR", 9); 
	
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "ABU SALEH", 3); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "ABDUL SABOOR", 2); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "ABDULLAH EJAZ", 5); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "ABU SALEH", 4); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "ALISHA GHAYAS", 1); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "BILAL HABIB", 2); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "EMAN RIZWAN", 2); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "FAHAD ALI", 4); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "HASEEB UR REHMAN", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD HUZAIFA", 10); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "IBRAHIM ARSHAD", 9); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "IBRAHIM FAROOQ", 7); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "KAUNAIN HUSSAIN", 3); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "KAZIM ALI SHAH", 4); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MALAIKA JUNAID", 1); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MALAIKA SATTAR", 1); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MOHAMMAD OSMAN ABDULLAH", 7); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD ABDUL SABOOR", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD MOHEEZ", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD MUSTAFA", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD SAFAAN UMAR", 9); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD SHAIEL", 5); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD USAMA UMER", 8); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUNIBA MANAAL", 5); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "RAMEEN JAMSHED", 3); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "SHAHZAIB KHAKWANI", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "SHEEZA TANVEER", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "SYEDA ALEEZA TAHIR", 2); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "TAHA AZMAT", 7); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "TALHA ASIF", 7); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "WASIF ALI", 8); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "ZAIN ULLAH UMAR", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "ZANEB AKHTAR", 2); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "JUNAID AHMED", 6); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "SARTAJ", 5); 
		
		academicGraph.addEdge("MUHAMMAD HUZAIFA", "MUHAMMAD ABDULLAH", 1); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "ABDUL HASEEB", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "ABDUL SABOOR", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "ABDULLAH EJAZ", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "ABU SALEH", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "BILAL HABIB", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "EMAN RIZWAN", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "FAHAD ALI", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "HASEEB UR REHMAN", 10); 
	
	   academicGraph.addEdge("MUHAMMAD MUSTAFA", "MUHAMMAD HUZAIFA", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "IBRAHIM ARSHAD", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "IBRAHIM FAROOQ", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "KAUNAIN HUSSAIN", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "KAZIM ALI SHAH", 1); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "MOHAMMAD OSMAN ABDULLAH", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "MUHAMMAD ABDUL SABOOR", 1); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "MUHAMMAD MOHEEZ", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "MUHAMMAD SAFAAN UMAR", 8); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "MUHAMMAD SHAIEL", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "MUHAMMAD USAMA UMER", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "SHAHZAIB KHAKWANI", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "SYEDA ALEEZA TAHIR", 9); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "TAHA AZMAT", 1); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "TALHA ASIF", 1); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "WASIF ALI", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "ZAIN ULLAH UMAR", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "SARTAJ", 10); 
	
	    academicGraph.addEdge("MUHAMMAD MUSTAFA", "MUHAMMAD ABDULLAH", 10); 
	
		academicGraph.addEdge("MUHAMMAD MUSTAFA", "PROFESSOR MUNEEBA", 6); 
		
		academicGraph.addEdge("MUHAMMAD MUSTAFA", "PROFESSOR YUSUF", 7); 
		
		academicGraph.addEdge("MUHAMMAD MUSTAFA", "PROFESSOR AHMED", 7); 
		
		academicGraph.addEdge("MUHAMMAD MUSTAFA", "PROFESSOR ZOBIA", 6); 
		
		academicGraph.addEdge("MUHAMMAD MUSTAFA", "PROFESSOR BUSHRA",6); 
	
	    academicGraph.addEdge("ABU SALEH", "ABDUL HASEEB", 7); 
	
	    academicGraph.addEdge("ABU SALEH", "ABDUL SABOOR", 7); 
	
	    academicGraph.addEdge("ABU SALEH", "ABDULLAH EJAZ", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "ALISHA GHAYAS", 5); 
	
	    academicGraph.addEdge("ABU SALEH", "BILAL HABIB", 7); 
	
	    academicGraph.addEdge("ABU SALEH", "EMAN RIZWAN", 5); 
	
	    academicGraph.addEdge("ABU SALEH", "FAHAD ALI", 7); 
	
	    academicGraph.addEdge("ABU SALEH", "HASEEB UR REHMAN", 9); 
	
		academicGraph.addEdge("ABU SALEH", "MUHAMMAD HUZAIFA", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "IBRAHIM ARSHAD", 10); 
	
	    academicGraph.addEdge("ABU SALEH", "IBRAHIM FAROOQ", 10); 
	
	    academicGraph.addEdge("ABU SALEH", "KAUNAIN HUSSAIN", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "KAZIM ALI SHAH", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "MALAIKA JUNAID", 5); 
	
	    academicGraph.addEdge("ABU SALEH", "MALAIKA SATTAR", 6); 
	
	    academicGraph.addEdge("ABU SALEH", "MOHAMMAD OSMAN ABDULLAH", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "MUHAMMAD ABDUL SABOOR", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "MUHAMMAD MOHEEZ", 10); 
	
	    academicGraph.addEdge("ABU SALEH", "MUHAMMAD MUSTAFA", 10); 
	
	    academicGraph.addEdge("ABU SALEH", "MUHAMMAD SAFAAN UMAR", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "MUHAMMAD SHAIEL", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "MUHAMMAD USAMA UMER", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "MUNIBA MANAAL", 7); 
	
	    academicGraph.addEdge("ABU SALEH", "RAMEEN JAMSHED", 5); 
	
	    academicGraph.addEdge("ABU SALEH", "SHAHZAIB KHAKWANI", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "SHEEZA TANVEER", 6); 
	
	    academicGraph.addEdge("ABU SALEH", "SYEDA ALEEZA TAHIR", 7); 
	
	    academicGraph.addEdge("ABU SALEH", "TAHA AZMAT", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "TALHA ASIF", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "WASIF ALI", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "ZAIN ULLAH UMAR", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "ZANEB AKHTAR", 5); 
	
	    academicGraph.addEdge("ABU SALEH", "JUNAID AHMED", 9); 
	
	    academicGraph.addEdge("ABU SALEH", "SARTAJ", 8); 
	
	    academicGraph.addEdge("ABU SALEH", "MUHAMMAD ABDULLAH", 8); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "ABDUL HASEEB", 5); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "ABDUL SABOOR", 3); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "ABDULLAH EJAZ", 7); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "ABU SALEH", 4); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "BILAL HABIB", 6); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "FAHAD ALI", 3); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "HASEEB UR REHMAN", 9); 
	
		academicGraph.addEdge( "MUHAMMAD SHAIEL", "MUHAMMAD HUZAIFA", 7); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "IBRAHIM ARSHAD", 5); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "IBRAHIM FAROOQ", 9); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "KAUNAIN HUSSAIN", 6); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "KAZIM ALI SHAH", 7); 
	
	 	academicGraph.addEdge( "MUHAMMAD SHAIEL", "MOHAMMAD OSMAN ABDULLAH", 9); 
	
	    academicGraph.addEdge( "MUHAMMAD SHAIEL", "MUHAMMAD ABDUL SABOOR", 5); 
	
		academicGraph.addEdge("MUHAMMAD SHAIEL", "MUHAMMAD MOHEEZ", 4); 
		
		academicGraph.addEdge(" MUHAMMAD SHAIEL", "MUHAMMAD MUSTAFA", 6); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "MUHAMMAD SAFAAN UMAR", 6); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "MUHAMMAD USAMA UMER", 7); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "SHAHZAIB KHAKWANI", 6); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "TAHA AZMAT", 7); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "TALHA ASIF", 7); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "ZAIN ULLAH UMAR", 5); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "JUNAID AHMED", 9); 
		
		academicGraph.addEdge("MUHAMMAD SHAIEL", "MUHAMMAD ABDULLAH", 1); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "ALISHA GHAYAS", 6); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "EMAN RIZWAN", 6); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "MALAIKA JUNAID", 6); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "MALAIKA SATTAR",6); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "MOHAMMAD OSMAN ABDULLAH", 2); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "MUNIBA MANAAL", 7); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "RAMEEN JAMSHED", 6); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "SHEEZA TANVEER", 6); 
		
		academicGraph.addEdge("ZANEB AKHTAR", "SYEDA ALEEZA TAHIR", 6); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "ABDUL SABOOR", 3); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "ABDULLAH EJAZ", 3); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "BILAL HABIB", 5); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "EMAN RIZWAN", 8); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "HASEEB UR REHMAN", 5); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MUHAMMAD HUZAIFA", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "IBRAHIM ARSHAD", 3); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "IBRAHIM FAROOQ", 6); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "KAUNAIN HUSSAIN", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "KAZIM ALI SHAH", 7); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MALAIKA JUNAID", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MALAIKA SATTAR", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MOHAMMAD OSMAN ABDULLAH", 6); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MUHAMMAD MOHEEZ", 3); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MUHAMMAD MUSTAFA", 8); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MUHAMMAD SAFAAN UMAR", 3); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MUHAMMAD USAMA UMER", 6); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "MUNIBA MANAAL", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "SHAHZAIB KHAKWANI", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "SHEEZA TANVEER", 3); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "SYEDA ALEEZA TAHIR", 9); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "TAHA AZMAT", 7); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "TALHA ASIF", 8); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "WASIF ALI", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "ZAIN ULLAH UMAR", 4); 
		
		academicGraph.addEdge("MUHAMMAD ABDUL SABOOR", "JUNAID AHMED", 3); 
		
		academicGraph.addEdge("SHEEZA", "ABDUL HASEEB", 1); 
	
	    academicGraph.addEdge("SHEEZA", "ABDUL SABOOR", 1); 
	
	    academicGraph.addEdge("SHEEZA", "ABDULLAH EJAZ", 1);
	
		academicGraph.addEdge("SHEEZA", "ABU SALEH", 1); 
		
		academicGraph.addEdge("SHEEZA", "ALISHA GHAYAS", 7); 
		
		academicGraph.addEdge("SHEEZA", "BILAL HABIB", 1); 
		
		academicGraph.addEdge("SHEEZA", "EMAN RIZWAN", 7); 
		
		academicGraph.addEdge("SHEEZA", "FAHAD ALI", 1); 
		
		academicGraph.addEdge("SHEEZA", "HASEEB UR REHMAN", 1); 
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD HUZAIFA", 1); 
		
		academicGraph.addEdge("SHEEZA", "IBRAHIM ARSHAD", 6); 
		
		academicGraph.addEdge("SHEEZA", "IBRAHIM FAROOQ", 6); 
		
		academicGraph.addEdge("SHEEZA", "KAUNAIN HUSSAIN", 1); 
		
		academicGraph.addEdge("SHEEZA", "KAZIM ALI SHAH", 1); 
		
		academicGraph.addEdge("SHEEZA", "MALAIKA JUNAID", 7); 
		
		academicGraph.addEdge("SHEEZA", "MALAIKA SATTAR", 7); 
		
		academicGraph.addEdge("SHEEZA", "MOHAMMAD OSMAN ABDULLAH", 8); 
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD ABDUL SABOOR", 2); 
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD MOHEEZ", 1); 
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD MUSTAFA", 2); 
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD SAFAAN UMAR", 7); 
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD SHAIEL", 1); 
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD USAMA UMER", 7); 
		
		academicGraph.addEdge("SHEEZA", "MUNIBA MANAAL", 7); 
		
		academicGraph.addEdge("SHEEZA", "RAMEEN JAMSHED", 7); 
		
		academicGraph.addEdge("SHEEZA", "SHAHZAIB KHAKWANI", 1);  
		
		academicGraph.addEdge("SHEEZA", "SYEDA ALEEZA TAHIR", 7); 
		
		academicGraph.addEdge("SHEEZA", "TAHA AZMAT", 7); 
		
		academicGraph.addEdge("SHEEZA", "TALHA ASIF", 2); 
		
		academicGraph.addEdge("SHEEZA", "WASIF ALI", 1); 
		
		academicGraph.addEdge("SHEEZA", "ZAIN ULLAH UMAR", 1); 
		
		academicGraph.addEdge("SHEEZA", "ZANEB AKHTAR", 8); 
		
		academicGraph.addEdge("SHEEZA", "JUNAID AHMED", 1); 
		
		academicGraph.addEdge("SHEEZA", "SARTAJ", 1);  
		
		academicGraph.addEdge("SHEEZA", "MUHAMMAD ABDULLAH", 1); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "ABDUL HASEEB", 1); 
	
	    academicGraph.addEdge("MUHAMMAD USAMA UMER", "ABDUL SABOOR", 1); 
	
	    academicGraph.addEdge("MUHAMMAD USAMA UMER", "ABDULLAH EJAZ", 1);
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "ABU SALEH", 3); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "ALISHA GHAYAS", 1); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "BILAL HABIB", 1); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "EMAN RIZWAN", 6); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "FAHAD ALI", 2); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "HASEEB UR REHMAN", 5); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "IBRAHIM ARSHAD", 10); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "IBRAHIM FAROOQ", 9); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "KAUNAIN HUSSAIN", 2); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "KAZIM ALI SHAH", 4);
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MALAIKA JUNAID", 2); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MALAIKA SATTAR", 3); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MOHAMMAD OSMAN ABDULLAH", 10); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUHAMMAD ABDUL SABOOR", 8); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUHAMMAD MOHEEZ", 1); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUHAMMAD MUSTAFA", 9); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUHAMMAD SAFAAN UMAR", 9); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUHAMMAD SHAIEL", 4); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUHAMMAD HUZAIFA", 7);
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUNIBA MANAAL", 8); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "RAMEEN JAMSHED", 5); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "SHAHZAIB KHAKWANI", 2); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "SHEEZA TANVEER", 8); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "SYEDA ALEEZA TAHIR", 9); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "TAHA AZMAT", 9); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "TALHA ASIF", 9); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "WASIF ALI", 2); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "ZAIN ULLAH UMAR", 1); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "ZANEB AKHTAR", 2); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "JUNAID AHMED", 4); 
		
		academicGraph.addEdge("MUHAMMAD USAMA UMER", "MUHAMMAD ABDULLAH", 1);  
		
		academicGraph.addEdge("FAHAD ALI", "ABDUL HASEEB", 5); 
		
		academicGraph.addEdge("FAHAD ALI", "ABDUL SABOOR", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "ABDULLAH EJAZ", 9); 
		
		academicGraph.addEdge("FAHAD ALI", "ABU SALEH", 5); 
		
		academicGraph.addEdge("FAHAD ALI", "BILAL HABIB", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "HASEEB UR REHMAN", 9); 
		
		academicGraph.addEdge("FAHAD ALI", "MUHAMMAD HUZAIFA", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "IBRAHIM ARSHAD", 6); 
		
		academicGraph.addEdge("FAHAD ALI", "IBRAHIM FAROOQ", 8); 
		
		academicGraph.addEdge("FAHAD ALI", "KAUNAIN HUSSAIN", 8); 
		
		academicGraph.addEdge("FAHAD ALI", "KAZIM ALI SHAH", 5); 
		
		academicGraph.addEdge("FAHAD ALI", "MOHAMMAD OSMAN ABDULLAH", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "MUHAMMAD ABDUL SABOOR", 6); 
		
		academicGraph.addEdge("FAHAD ALI", "MUHAMMAD MOHEEZ", 5); 
		
		academicGraph.addEdge("FAHAD ALI", "MUHAMMAD MUSTAFA", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "MUHAMMAD SAFAAN UMAR", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "MUHAMMAD SHAIEL", 6); 
		
		academicGraph.addEdge("FAHAD ALI", "MUHAMMAD USAMA UMER", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "MUNIBA MANAAL", 3); 
		
		academicGraph.addEdge("FAHAD ALI", "SHAHZAIB KHAKWANI", 6); 
		
		academicGraph.addEdge("FAHAD ALI", "TAHA AZMAT", 7); 
		
		academicGraph.addEdge("FAHAD ALI", "TALHA ASIF", 5); 
		
		academicGraph.addEdge("FAHAD ALI", "WASIF ALI", 8); 
		
		academicGraph.addEdge("FAHAD ALI", "ZAIN ULLAH UMAR", 9); 
		
		academicGraph.addEdge("FAHAD ALI", "FAHAD ALI", 9); 
		
		academicGraph.addEdge("FAHAD ALI", "JUNAID AHMED", 9); 
		
		academicGraph.addEdge("FAHAD ALI", "SARTAJ", 9); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "ALISHA GHAYAS", 10); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "EMAN RIZWAN", 10); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "IBRAHIM FAROOQ", 4); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "MALAIKA JUNAID", 10); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "MALAIKA SATTAR", 10); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "MOHAMMAD OSMAN ABDULLAH", 8); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "MUHAMMAD ABDUL SABOOR", 1); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "MUHAMMAD MUSTAFA", 1); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "MUHAMMAD USAMA UMER", 5); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "MUNIBA MANAAL", 10); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "SHEEZA TANVEER", 10); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "SYEDA ALEEZA TAHIR", 10); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "TAHA AZMAT", 1); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "TALHA ASIF", 1); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "WASIF ALI", 1); 
		
		academicGraph.addEdge("RAMEEN JAMSHED", "ZANEB AKHTAR", 10); 
		
		academicGraph.addEdge("BILAL HABIB", "ABDUL HASEEB", 6); 
		
		academicGraph.addEdge("BILAL HABIB", "ABDUL SABOOR", 10); 
		
		academicGraph.addEdge("BILAL HABIB", "ABDULLAH EJAZ", 9); 
		
		academicGraph.addEdge("BILAL HABIB", "ABU SALEH", 5); 
		
		academicGraph.addEdge("BILAL HABIB", "FAHAD ALI", 6); 
		
		academicGraph.addEdge("BILAL HABIB", "HASEEB UR REHMAN", 8); 
		
		academicGraph.addEdge("BILAL HABIB", "MUHAMMAD HUZAIFA", 3); 
		
		academicGraph.addEdge("BILAL HABIB", "IBRAHIM ARSHAD", 2); 
		
		academicGraph.addEdge("BILAL HABIB", "IBRAHIM FAROOQ", 5); 
		
		academicGraph.addEdge("BILAL HABIB", "KAUNAIN HUSSAIN", 7); 
		
		academicGraph.addEdge("BILAL HABIB", "KAZIM ALI SHAH", 7); 
	
		academicGraph.addEdge("BILAL HABIB", "MOHAMMAD OSMAN ABDULLAH", 4); 
		
		academicGraph.addEdge("BILAL HABIB", "MUHAMMAD ABDUL SABOOR", 8); 
		
		academicGraph.addEdge("BILAL HABIB", "MUHAMMAD MUSTAFA", 9); 
		
		academicGraph.addEdge("BILAL HABIB", "MUHAMMAD SAFAAN UMAR", 4); 
		
		academicGraph.addEdge("BILAL HABIB", "MUHAMMAD SHAIEL", 5); 
		
		academicGraph.addEdge("BILAL HABIB", "MUHAMMAD USAMA UMER", 3); 
		
		academicGraph.addEdge("BILAL HABIB", "MUNIBA MANAAL", 9); 
		
		academicGraph.addEdge("BILAL HABIB", "RAMEEN JAMSHED", 9); 
		
		academicGraph.addEdge("BILAL HABIB", "SHAHZAIB KHAKWANI", 4); 
		
		academicGraph.addEdge("BILAL HABIB", "TAHA AZMAT", 8); 
		
		academicGraph.addEdge("BILAL HABIB", "TALHA ASIF",8); 
		
		academicGraph.addEdge("BILAL HABIB", "WASIF ALI", 6); 
		
		academicGraph.addEdge("BILAL HABIB", "ZAIN ULLAH UMAR",5); 
		
		academicGraph.addEdge("BILAL HABIB", "JUNAID AHMED", 6); 
		
		academicGraph.addEdge("BILAL HABIB", "SARTAJ", 4); 
		
		academicGraph.addEdge("BILAL HABIB", "MUHAMMAD ABDULLAH", 5); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "ABDUL HASEEB", 9); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "ABDUL SABOOR", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "ABDULLAH EJAZ", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "ABU SALEH", 8); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "BILAL HABIB", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "FAHAD ALI", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MUHAMMAD HUZAIFA", 7); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "IBRAHIM ARSHAD", 7); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "IBRAHIM FAROOQ", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "KAUNAIN HUSSAIN", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "KAZIM ALI SHAH", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MOHAMMAD OSMAN ABDULLAH", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MUHAMMAD ABDUL SABOOR", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MUHAMMAD MOHEEZ", 8); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MUHAMMAD MUSTAFA", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MUHAMMAD SAFAAN UMAR", 7); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MUHAMMAD SHAIEL", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "MUHAMMAD USAMA UMER", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "SHAHZAIB KHAKWANI", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "TAHA AZMAT", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "TALHA ASIF", 9); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "WASIF ALI", 10); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "ZAIN ULLAH UMAR", 7); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "HASEEB UR REHMAN", 9); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "JUNAID AHMED", 9); 
		
		academicGraph.addEdge("HASEEB UR REHMAN", "SARTAJ", 8); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", " ABDUL HASEEB ", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", " ABDUL SABOOR ", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", " ABDULLAH EJAZ ", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "ABU SALEH", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "ALISHA GHAYAS", 1); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "BILAL HABIB", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "EMAN RIZWAN", 1); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "FAHAD ALI", 9); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "HASEEB UR REHMAN", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "IBRAHIM ARSHAD", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "IBRAHIM FAROOQ", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "KAUNAIN HUSSAIN", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "KAZIM ALI SHAH ", 9); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MOHAMMAD OSMAN ABDULLAH", 9); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MALAIKA SATTAR", 6); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MUHAMMAD ABDUL SABOOR", 9); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MUHAMMAD MOHEEZ", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MUHAMMAD MUSTAFA", 9); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MUHAMMAD SAFAAN UMAR", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MUHAMMAD SHAIEL", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MUHAMMAD USAMA UMER", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "MUNIBA MANAAL", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "RAMEEN JAMSHED", 9); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "SHAHZAIB KHAKWANI", 8); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "SHEEZA TANVEER", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "SYEDA ALEEZA TAHIR", 1); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "TAHA AZMAT", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "TALHA ASIF", 10); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "WASIF ALI", 8); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "ZAIN ULLAH UMAR", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "ZANEB AKHTAR", 5); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "JUNAID AHMED", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", "SARTAJ", 7); 
		
		academicGraph.addEdge("MOHAMMAD OSMAN ABDULLAH", " MUHAMMAD ABDULLAH ", 7); 
		
		academicGraph.addEdge("TALHA ASIF", " ABDUL HASEEB ", 7); 
		
		academicGraph.addEdge("TALHA ASIF", " ABDUL SABOOR ", 8); 
		
		academicGraph.addEdge("TALHA ASIF", " ABDULLAH EJAZ ", 8); 
		
		academicGraph.addEdge("TALHA ASIF", "ABU SALEH", 7); 
		
		academicGraph.addEdge("TALHA ASIF", "BILAL HABIB", 8); 
		
		academicGraph.addEdge("TALHA ASIF", "EMAN RIZWAN", 9); 
		
		academicGraph.addEdge("TALHA ASIF", "MUHAMMAD HUZAIFA", 7); 
		
		academicGraph.addEdge("TALHA ASIF", "HASEEB UR REHMAN", 7); 
		
		academicGraph.addEdge("TALHA ASIF", "IBRAHIM ARSHAD", 7); 
		
		academicGraph.addEdge("TALHA ASIF", "IBRAHIM FAROOQ", 9); 
		
		academicGraph.addEdge("TALHA ASIF", "KAUNAIN HUSSAIN", 8); 
		
		academicGraph.addEdge("TALHA ASIF", " KAZIM ALI SHAH", 9); 
		
		academicGraph.addEdge("TALHA ASIF", "MALAIKA JUNAID", 8); 
		
		academicGraph.addEdge("TALHA ASIF", "MOHAMMAD OSMAN ABDULLAH", 7); 
		
		academicGraph.addEdge("TALHA ASIF", "MUHAMMAD ABDUL SABOOR", 9); 
		
		academicGraph.addEdge("TALHA ASIF", "MUHAMMAD MOHEEZ", 8); 
		
		academicGraph.addEdge("TALHA ASIF", "MUHAMMAD MUSTAFA", 10); 
		
		academicGraph.addEdge("TALHA ASIF", "MUHAMMAD SHAIEL", 8); 
		
		academicGraph.addEdge("TALHA ASIF", "MUHAMMAD USAMA UMER", 8); 
		
		academicGraph.addEdge("TALHA ASIF", "SHAHZAIB KHAKWANI", 8); 
		
		academicGraph.addEdge("TALHA ASIF", "SYEDA ALEEZA TAHIR", 9); 
		
		academicGraph.addEdge("TALHA ASIF", "TAHA AZMAT", 9); 
		
		academicGraph.addEdge("TALHA ASIF", "WASIF ALI", 7); 
		
		academicGraph.addEdge("TALHA ASIF", "ZAIN ULLAH UMAR", 9); 
		
		academicGraph.addEdge("TALHA ASIF", "JUNAID AHMED", 7); 
		
		academicGraph.addEdge("TALHA ASIF", "SARTAJ", 7); 
		
		academicGraph.addEdge("ABDUL HASEEB", "ABDUL SABOOR ", 6); 
		
		academicGraph.addEdge("ABDUL HASEEB", " ABDULLAH EJAZ ", 10); 
		
		academicGraph.addEdge("ABDUL HASEEB", "ABU SALEH", 8); 
		
		academicGraph.addEdge("ABDUL HASEEB", "ALISHA GHAYAS", 2); 
		
		academicGraph.addEdge("ABDUL HASEEB", "BILAL HABIB", 6); 
		
		academicGraph.addEdge("ABDUL HASEEB", "EMAN RIZWAN", 3); 
		
		academicGraph.addEdge("ABDUL HASEEB", "FAHAD ALI", 6); 
		
		academicGraph.addEdge("ABDUL HASEEB", "HASEEB UR REHMAN", 8); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUHAMMAD HUZAIFA", 6); 
		
		academicGraph.addEdge("ABDUL HASEEB", "IBRAHIM ARSHAD", 5); 
		
		academicGraph.addEdge("ABDUL HASEEB", "IBRAHIM FAROOQ", 10); 
		
		academicGraph.addEdge("ABDUL HASEEB", "KAUNAIN HUSSAIN", 7); 
		
		academicGraph.addEdge("ABDUL HASEEB", " KAZIM ALI SHAH ", 9); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MALAIKA JUNAID", 3); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MALAIKA SATTAR", 3); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MOHAMMAD OSMAN ABDULLAH", 7); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUHAMMAD ABDUL SABOOR", 9); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUHAMMAD MOHEEZ", 10); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUHAMMAD MUSTAFA", 10); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUHAMMAD SAFAAN UMAR", 4); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUHAMMAD SHAIEL", 9); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUHAMMAD USAMA UMER", 5); 
		
		academicGraph.addEdge("ABDUL HASEEB", "MUNIBA MANAAL", 4); 
		
		academicGraph.addEdge("ABDUL HASEEB", "RAMEEN JAMSHED", 3); 
		
		academicGraph.addEdge("ABDUL HASEEB", "SHAHZAIB KHAKWANI", 10); 
		
		academicGraph.addEdge("ABDUL HASEEB", "SHEEZA TANVEER", 3); 
		
		academicGraph.addEdge("ABDUL HASEEB", "SYEDA ALEEZA TAHIR", 4); 
		
		academicGraph.addEdge("ABDUL HASEEB", "TAHA AZMAT", 9); 
		
		academicGraph.addEdge("ABDUL HASEEB", "TALHA ASIF", 9); 
		
		academicGraph.addEdge("ABDUL HASEEB", "WASIF ALI", 9); 
		
		academicGraph.addEdge("ABDUL HASEEB", "ZAIN ULLAH UMAR", 8); 
		
		academicGraph.addEdge("ABDUL HASEEB", "ZANEB AKHTAR", 2); 
		
		academicGraph.addEdge("ABDUL HASEEB", "ABDUL HASEEB", 9); 
		
		academicGraph.addEdge("ABDUL HASEEB", "JUNAID AHMED", 6); 
		
		academicGraph.addEdge("ABDUL HASEEB", "SARTAJ", 6); 
		
		academicGraph.addEdge("ABDUL HASEEB", " MUHAMMAD ABDULLAH ", 5); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "MUHAMMAD HUZAIFA", 8); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "IBRAHIM FAROOQ", 1); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "MOHAMMAD OSMAN ABDULLAH", 8); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "MUHAMMAD MUSTAFA", 10); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "MUHAMMAD SAFAAN UMAR", 10); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "MUHAMMAD USAMA UMER", 9); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "SHEEZA TANVEER", 8); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "TAHA AZMAT", 5); 
		
		academicGraph.addEdge("IBRAHIM ARSHAD", "TALHA ASIF", 7); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "ALISHA GHAYAS", 8); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "EMAN RIZWAN", 8); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "IBRAHIM ARSHAD", 2); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "IBRAHIM FAROOQ", 3); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "MALAIKA SATTAR", 3); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "MOHAMMAD OSMAN ABDULLAH", 3); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "MUHAMMAD ABDUL SABOOR", 3); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "MUHAMMAD MUSTAFA", 4); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "MUHAMMAD SAFAAN UMAR", 1); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "MUHAMMAD USAMA UMER", 3); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "MUNIBA MANAAL", 7); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "RAMEEN JAMSHED", 8); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "SHEEZA TANVEER", 8); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "SYEDA ALEEZA TAHIR", 8); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "TAHA AZMAT", 3); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "TALHA ASIF", 4); 
		
		academicGraph.addEdge("MALAIKA JUNAID", " ZANEB AKHTAR ", 8); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "PROFESSOR YUSUF", 5); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "PROFESSOR AHMED",6); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "PROFESSOR  ZOBIA", 6); 
		
		academicGraph.addEdge("MALAIKA JUNAID", "PROFESSOR BUSHRA",7); 
		
		academicGraph.addEdge("TAHA AZMAT", "ABDUL HASEEB", 3); 
		
		academicGraph.addEdge("TAHA AZMAT", " ABDUL SABOOR ", 3); 
		
		academicGraph.addEdge("TAHA AZMAT", " ABDULLAH EJAZ ", 4); 
		
		academicGraph.addEdge("TAHA AZMAT", "ABU SALEH", 1); 
		
		academicGraph.addEdge("TAHA AZMAT", "BILAL HABIB", 4); 
		
		academicGraph.addEdge("TAHA AZMAT", "EMAN RIZWAN", 8); 
	
		academicGraph.addEdge("TAHA AZMAT", "FAHAD ALI", 3); 
		
		academicGraph.addEdge("TAHA AZMAT", "HASEEB UR REHMAN", 5); 
		
		academicGraph.addEdge("TAHA AZMAT", " MUHAMMAD HUZAIFA ", 5); 
		
		academicGraph.addEdge("TAHA AZMAT", "IBRAHIM ARSHAD", 7); 
		
		academicGraph.addEdge("TAHA AZMAT", "IBRAHIM FAROOQ", 7); 
		
		academicGraph.addEdge("TAHA AZMAT", "KAUNAIN HUSSAIN", 3); 
		
		academicGraph.addEdge("TAHA AZMAT", " KAZIM ALI SHAH", 9); 
		
		academicGraph.addEdge("TAHA AZMAT", "MOHAMMAD OSMAN ABDULLAH", 9); 
		
		academicGraph.addEdge("TAHA AZMAT", "MUHAMMAD ABDUL SABOOR", 9); 
		
		academicGraph.addEdge("TAHA AZMAT", "MUHAMMAD MOHEEZ", 4); 
		
		academicGraph.addEdge("TAHA AZMAT", "MUHAMMAD MUSTAFA", 9); 
		
		academicGraph.addEdge("TAHA AZMAT", "MUHAMMAD SAFAAN UMAR", 4); 
		
		academicGraph.addEdge("TAHA AZMAT", "MUHAMMAD SHAIEL", 4); 
		
		academicGraph.addEdge("TAHA AZMAT", "MUHAMMAD USAMA UMER", 6); 
		
		academicGraph.addEdge("TAHA AZMAT", "RAMEEN JAMSHED", 4); 
		
		academicGraph.addEdge("TAHA AZMAT", "SHAHZAIB KHAKWANI", 3); 
		
		academicGraph.addEdge("TAHA AZMAT", "SHEEZA TANVEER", 8); 
		
		academicGraph.addEdge("TAHA AZMAT", "SYEDA ALEEZA TAHIR", 9); 
		
		academicGraph.addEdge("TAHA AZMAT", " MUHAMMAD ABDULLAH ", 3); 
		
		academicGraph.addEdge("TAHA AZMAT", "TALHA ASIF", 9); 
		
		academicGraph.addEdge("TAHA AZMAT", "WASIF ALI", 4); 
		
		academicGraph.addEdge("TAHA AZMAT", "ZAIN ULLAH UMAR", 2); 
		
		academicGraph.addEdge("TAHA AZMAT", "JUNAID AHMED", 3); 
		
		academicGraph.addEdge("TAHA AZMAT", "SARTAJ", 2); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "BILAL HABIB", 6); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "IBRAHIM FAROOQ", 8); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "MUHAMMAD MOHEEZ", 9); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "MUHAMMAD MUSTAFA", 8); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "SHAHZAIB KHAKWANI", 10); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "TAHA AZMAT", 7); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "TALHA ASIF", 7); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "WASIF ALI", 10); 
		
		academicGraph.addEdge("ZAIN ULLAH UMAR", "SARTAJ", 9); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "ABDUL HASEEB", 10); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "ABDUL SAABOOR", 6); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "ABDULLAH EJAZ", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "ABU SALEH", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "ALISHA GHAYAS", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "BILAL HABIB", 5); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "EMAN RIZWAN", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "FAHAD ALI", 6); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "HASEEB UR REHMAN", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD HUZAIFA", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "IBRAHIM ARSHAD", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "IBRAHIM FAROOQ", 10); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "KAUNAIN HUSSAIN", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "KAZIM ALI SHAH", 6); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MALAIKA JUNAID", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MALAIKA SATTAR", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MOHAMMAD OSMAN ABDULLAH", 7); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD ABDUL SABOOR", 6); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD MOHEEZ", 10); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD MUSTAFA", 10); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD SAFAAN UMAR", 3); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD SHAIEL", 9); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD USAMA UMER", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUNIBA MANAAL", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "SHEEZA TANVEER", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "SYEDA ALEEZA TAHIR", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "TAHA AZMAT", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "TALHA ASIF", 8); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "WASIF ALI", 10); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "ZAIN ULLAH UMAR", 10); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "ZANEB AKHTAR", 1); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "JUNAID AHMED", 7); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "SARTAJ", 10); 
		
		academicGraph.addEdge("SHAHZAIB KHAKWANI", "MUHAMMAD ABDULLAH", 5); 
	
	
	academicGraph.dijkstra("SHAHZAIB KHAKWANI", "PROFESSOR ZOBIA");
	
	    return 0;
} 
