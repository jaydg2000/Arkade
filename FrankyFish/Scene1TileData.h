#pragma once

#define TILES_LENGTH 1027

int scene_tiles[] = { 0,0,27,0,1,0,9,11,0,0,1,0,3,0,0,1,9,12,0,0,
2,9,23,0,0,3,0,3,0,0,3,9,23,0,0,4,9,23,0,0,
5,0,13,0,0,5,1,15,0,1,5,9,25,0,0,6,0,9,0,0,7,0,8,0,0,
7,9,23,0,0,8,9,25,0,0,9,0,9,0,0,
10,0,4,0,1,10,9,23,0,0,11,0,2,0,0,11,9,23,0,0,12,0,1,0,0,
12,5,17,0,0,12,9,4,1,0,13,0,3,0,0,13,9,13,0,0,
14,9,9,0,0,15,0,2,0,0,15,9,26,0,1,16,0,3,0,0,16,9,23,0,0,
17,9,23,0,0,18,0,3,0,0,18,9,23,0,0,19,0,9,0,0,19,1,17,0,1,19,9,20,0,0,
20,0,8,0,0,20,9,20,1,0,21,9,25,0,0,22,0,4,0,1,
23,0,3,0,0,23,9,24,0,0,24,6,15,0,0,24,9,4,1,0,25,0,1,0,0,
25,9,8,0,0,26,0,2,0,0,27,0,23,0,1,27,9,8,0,0,
28,0,2,0,0,29,0,3,0,0,29,9,4,0,0,
30,9,23,0,0,31,0,2,0,0,31,9,25,0,0,32,0,1,0,0,
33,0,3,0,0,33,9,23,0,0,34,9,25,0,0,35,0,1,0,0,
36,0,2,0,0,36,9,23,0,0,37,0,3,0,0,37,9,24,0,0,
38,9,25,0,0,39,0,2,0,0,40,0,3,0,0,40,9,24,0,0,
41,9,25,0,0,42,0,1,0,0,43,0,3,0,0,43,6,15,1,0,43,9,6,0,0,
44,9,8,0,0,45,0,2,0,0,46,0,1,0,0,46,9,8,0,0,
47,0,3,0,0,48,9,4,0,0,49,0,3,0,0,
49,9,25,0,0,51,0,2,0,0,51,9,23,0,0,
52,0,1,0,0,52,9,24,0,0,53,0,28,0,0,53,1,5,0,0,53,9,23,0,0,54,0,9,0,0,
54,1,28,0,0,54,2,5,0,0,54,9,24,0,0,55,0,13,0,0,55,1,9,0,0,55,2,28,0,0,55,3,17,0,1,55,9,23,0,0,56,0,8,0,0,56,1,13,0,0,
56,2,9,0,0,56,9,23,0,0,57,1,9,0,0,57,2,9,0,0,57,9,25,0,0,58,0,26,0,0,58,1,19,0,0,
59,0,1,0,0,59,8,11,0,0,59,9,6,0,0,60,0,3,0,0,60,8,12,0,0,60,9,8,0,0,
61,5,27,0,0,61,6,10,0,0,61,8,6,0,0,62,0,2,0,0,62,5,29,0,0,62,6,4,0,0,62,7,8,0,0,62,8,8,0,0,62,9,8,0,0,63,0,3,0,0,
63,6,25,0,0,64,7,9,0,0,64,8,13,0,0,64,9,9,0,0,65,0,2,0,0,65,6,23,0,0,
65,7,9,0,0,65,8,9,0,0,65,9,13,0,0,66,0,28,0,0,66,1,19,1,0,66,3,5,0,0,66,6,24,0,0,66,7,8,0,0,66,8,8,0,0,66,9,8,0,0,67,0,8,0,0,67,1,13,0,0,67,2,8,0,0,67,3,3,0,0,67,6,25,0,0,
68,1,8,0,0,68,7,8,0,0,68,8,8,0,0,68,9,8,0,0,69,0,13,0,0,69,2,26,0,0,69,3,7,0,0,69,6,23,0,0,70,0,26,0,0,70,1,14,1,0,
70,2,7,0,0,70,6,25,0,0,70,7,8,0,0,70,8,8,0,0,70,9,8,0,0,71,0,2,0,0,72,0,3,0,0,
72,6,29,0,0,72,7,4,0,0,72,8,8,0,0,72,9,8,0,0,73,4,15,0,0,73,7,6,0,0,74,0,2,0,0,
74,7,8,0,0,74,8,8,0,0,74,9,8,0,0,75,0,1,0,0,76,0,2,0,0,76,7,8,0,0,
76,8,8,0,0,76,9,8,0,0,77,0,1,0,0,78,0,2,0,0,78,7,4,0,0,78,8,13,0,0,
78,9,8,0,0,79,0,3,0,0,79,7,29,0,0,79,8,4,0,0,80,8,25,0,0,80,9,13,0,0,
81,0,3,0,0,81,9,9,0,0,82,8,29,0,0,82,9,4,0,0,83,0,2,0,0,
83,9,25,0,0,84,0,1,0,0,85,0,3,0,0,85,9,24,0,0,
86,9,25,0,0,87,0,2,0,0,88,0,3,0,0,88,9,24,0,0,
89,9,24,0,0,90,0,2,0,0,90,9,23,0,0,91,0,1,0,0,91,9,24,0,0,
92,0,3,0,0,92,6,16,0,0,92,9,6,0,0,93,9,8,0,0,94,0,28,0,0,
94,1,5,0,0,95,0,9,0,0,95,1,28,0,0,95,2,17,0,1,95,9,9,0,0,96,0,8,0,0,96,1,8,0,0,
96,8,18,0,0,96,9,8,0,0,98,0,9,0,0,98,1,26,0,0,
98,9,9,0,0,99,0,8,0,0,99,1,2,0,0,99,8,27,0,0,99,9,6,0,0,100,1,1,0,0,100,8,25,0,0,100,9,8,0,0,
101,0,26,0,0,101,1,7,0,0,102,0,2,0,0,102,5,27,0,0,102,6,10,0,0,102,8,6,0,0,102,9,8,0,0,103,0,3,0,0,
103,5,25,0,0,103,6,8,0,0,103,7,8,0,0,103,8,13,0,0,104,8,8,0,0,104,9,13,0,0,105,0,28,0,0,105,1,5,0,0,105,5,29,0,0,
105,6,4,0,0,105,7,13,0,0,105,9,8,0,0,106,0,8,0,0,106,1,3,0,0,106,5,27,0,0,106,6,6,0,0,106,7,8,0,0,106,8,9,0,0,107,4,27,0,0,107,5,6,0,0,107,6,9,0,0,
107,8,13,0,0,107,9,9,0,0,108,0,8,0,0,108,1,3,0,0,108,4,29,0,0,108,5,4,0,0,108,6,13,0,0,108,7,8,0,0,108,8,8,0,0,108,9,13,0,0,109,5,29,0,0,109,6,4,0,0,
109,9,8,0,0,110,0,8,0,0,110,1,3,0,0,110,6,29,0,0,110,7,4,0,0,110,8,13,0,0,111,7,29,0,0,111,8,4,0,0,111,9,8,0,0,
112,0,8,0,0,112,1,2,0,0,112,8,25,0,0,113,1,1,0,0,113,9,8,0,0,114,0,9,0,0,
114,1,2,0,0,114,8,24,0,0,115,0,26,0,0,115,1,7,0,0,115,8,29,0,0,115,9,4,0,0,116,0,3,0,0,
116,9,25,0,0,118,0,2,0,0,118,9,24,0,0,
119,0,1,0,0,119,9,23,0,0,120,0,1,0,0,120,9,24,0,0,121,0,2,0,0,
121,9,23,0,0,122,0,1,0,0,122,9,25,0,0,123,0,3,0,0,
124,9,23,0,0,125,0,1,0,0,125,9,24,0,0,126,0,3,0,0,126,9,23,0,0,
127,9,23,0,0,128,0,1,0,0,128,9,24,0,0,129,0,28,0,0,129,1,10,0,0,129,3,5,0,0,129,9,25,0,0,
130,0,8,0,0,130,1,9,0,0,130,2,8,0,0,130,3,28,0,0,130,4,14,0,0,130,5,5,0,0,131,1,8,0,0,131,3,13,0,0,131,4,9,0,0,131,5,2,0,0,131,9,24,0,0,132,0,13,0,0,
132,2,26,0,0,132,3,19,0,0,132,5,7,0,0,132,9,25,0,0,133,0,9,0,0,133,1,26,0,0,133,2,7,0,0,134,0,26,0,0,134,1,7,0,0,
134,9,24,0,0,135,0,3,0,0,135,9,25,0,0,
137,0,1,0,0,137,9,23,0,0,138,0,3,0,0,138,9,24,0,0,
139,9,25,0,0,140,0,1,0,0,141,0,2,0,0,141,9,24,0,0,
142,0,3,0,0,142,9,25,0,0,144,0,1,0,0,
144,9,25,0,0,145,0,3,0,0,146,9,25,0,0,
147,0,1,0,0,148,0,2,0,0,148,9,24,0,0,149,0,3,0,0,
149,9,23,0,0,150,9,23,0,0,151,0,3,0,0,151,9,24,0,0,
152,9,24,0,0,153,0,2,0,0,153,9,23,0,0,154,0,3,0,0,154,8,27,0,0,154,9,6,0,0,
155,5,15,0,0,155,8,6,0,0,155,9,13,0,0,156,0,28,0,0,156,1,5,0,0,156,8,8,0,0,156,9,9,0,0,157,0,9,0,0,157,1,28,0,0,
157,9,8,0,0,158,0,13,0,0,158,1,13,0,0,158,2,16,0,1,158,8,9,0,0,159,0,8,0,0,159,1,9,0,0,159,8,13,0,0,159,9,8,0,0,
160,1,13,0,0,160,8,4,0,0,161,0,13,0,0,161,1,13,0,0,161,8,29,0,0,161,9,4,0,0,162,0,9,0,0,162,1,26,0,0,
162,9,25,0,0,163,0,26,0,0,163,1,7,0,0,164,0,3,0,0,164,9,23,0,0,
165,9,25,0,0,166,0,1,0,0,167,0,3,0,0,167,9,24,0,0,
168,9,23,0,0,169,0,3,0,0,169,9,25,0,0,
171,0,3,0,0,171,9,25,0,0,173,0,1,0,0,
173,9,23,0,0,174,0,3,0,0,174,9,24,0,0,175,9,23,0,0,
176,0,3,0,0,176,9,24,0,0,177,0,3,0,0,177,9,24,0,0,178,0,3,0,0,
178,9,25,0,0,180,0,3,0,0,180,9,24,0,0,
181,9,23,0,0,182,0,1,0,0,182,9,24,0,0,183,0,3,0,0,183,9,23,0,0,
184,5,17,0,0,184,9,6,0,0,185,0,3,0,0,185,9,8,0,0,
187,0,28,0,0,187,1,17,0,1,187,9,4,0,0,188,0,8,0,0,188,9,24,0,0,
189,6,16,0,0,189,9,6,0,0,190,0,26,0,0,190,9,8,0,0,191,0,3,0,0,
192,9,13,0,0,193,0,28,0,0,193,1,16,0,1,193,9,4,0,0,194,0,9,0,0,194,9,24,0,0,
195,0,8,0,0,195,5,17,0,0,195,9,6,0,0,196,9,9,0,0,197,0,26,0,0,
197,9,9,0,0,198,0,28,0,0,198,1,5,0,0,198,9,4,0,0,199,0,8,0,0,199,1,28,0,0,199,2,5,0,0,199,9,23,0,0,
200,1,13,0,0,200,2,2,0,0,200,6,27,0,0,200,7,10,0,0,200,9,6,0,0,201,0,13,0,0,201,1,26,0,0,201,2,7,0,0,201,5,27,0,0,201,6,6,0,0,201,7,8,0,0,201,8,9,0,0,201,9,9,0,0,202,0,8,0,0,202,1,3,0,0,
202,4,27,0,0,202,5,6,0,0,202,6,8,0,0,202,8,8,0,0,202,9,8,0,0,203,4,20,0,0,203,5,13,0,0,203,7,13,0,0,204,0,13,0,0,204,1,2,0,0,204,4,12,0,0,
204,5,9,0,0,204,6,8,0,0,204,7,8,0,0,204,8,13,0,0,204,9,8,0,0,205,0,26,0,0,205,1,7,0,0,205,3,27,0,0,205,4,6,0,0,205,5,8,0,0,205,8,9,0,0,206,0,3,0,0,206,3,25,0,0,206,4,8,0,0,
206,6,13,0,0,206,7,9,0,0,206,8,9,0,0,206,9,13,0,0,207,5,8,0,0,207,6,9,0,0,207,7,9,0,0,207,8,9,0,0,207,9,8,0,0,208,0,3,0,0,208,3,29,0,0,208,4,4,0,0,208,6,13,0,0,
208,7,13,0,0,208,8,8,0,0,209,4,29,0,0,209,5,4,0,0,209,6,9,0,0,209,7,9,0,0,209,9,9,0,0,210,0,3,0,0,210,5,29,0,0,210,6,4,0,0,210,7,13,0,0,
210,8,9,0,0,210,9,9,0,0,211,6,25,0,0,211,7,8,0,0,211,8,13,0,0,211,9,9,0,0,212,0,2,0,0,212,8,13,0,0,
212,9,8,0,0,213,0,1,0,0,213,6,24,0,0,213,7,9,0,0,213,8,8,0,0,214,0,2,0,0,214,6,29,0,0,214,7,4,0,0,214,9,13,0,0,
215,0,1,0,0,215,7,29,0,0,215,8,4,0,0,215,9,8,0,0,216,0,3,0,0,216,7,27,0,0,216,8,6,0,0,
217,4,27,0,0,217,5,10,0,0,217,7,6,0,0,217,8,9,0,0,217,9,9,0,0,218,0,2,0,0,218,4,25,0,0,218,5,8,0,0,218,6,9,0,0,218,7,9,0,0,218,8,9,0,0,218,9,9,0,0,219,0,1,0,0,
219,6,8,0,0,219,7,9,0,0,219,8,8,0,0,219,9,8,0,0,220,0,1,0,0,220,4,29,0,0,220,5,4,0,0,220,7,9,0,0,221,0,3,0,0,221,5,23,0,0,221,6,9,0,0,
221,7,8,0,0,221,8,9,0,0,221,9,9,0,0,222,5,25,0,0,222,6,9,0,0,222,8,9,0,0,222,9,8,0,0,223,0,1,0,0,223,6,8,0,0,223,7,9,0,0,
223,8,8,0,0,224,0,2,0,0,224,5,24,0,0,224,7,9,0,0,224,9,9,0,0,225,0,1,0,0,225,5,29,0,0,225,6,19,0,0,225,8,4,0,0,
225,9,9,0,0,226,0,1,0,0,226,8,29,0,0,226,9,4,0,0,227,0,3,0,0,227,9,24,0,0,
228,9,23,0,0,229,0,1,0,0,229,6,15,0,0,229,9,6,0,0,230,0,2,0,0,230,9,8,0,0,
231,0,1,0,0,232,0,2,0,0,232,9,8,0,0,233,0,2,0,0,
234,0,1,0,0,234,9,8,0,0,235,0,1,0,0,235,6,16,0,0,236,0,1,0,0,
236,9,8,0,0,237,0,2,0,0,238,0,3,0,0,238,9,9,0,0,
239,8,11,0,0,239,9,8,0,0,240,0,1,0,0,240,8,12,0,0,241,0,2,0,0,241,8,29,0,0,
241,9,4,0,0,242,0,28,0,0,242,1,5,0,0,242,9,25,0,0,243,0,8,0,0,243,1,3,0,0,
244,9,23,0,0,245,0,8,0,0,245,1,2,0,0,245,9,24,0,0,246,1,1,0,0,246,9,23,0,0,
247,0,9,0,0,247,1,1,0,0,247,9,24,0,0,248,0,26,0,0,248,1,7,0,0,248,9,25,0,0,249,0,2,0,0,
250,0,1,0,0,250,9,24,0,0,251,0,2,0,0,251,9,25,0,0,252,0,2,0,0,
253,0,1,0,0,253,9,24,0,0,254,0,1,0,0,254,9,25,0,0,255,0,2,0,0,
256,0,1,0,0,256,9,25,0,0,257,0,1,0,0,258,0,2,0,0,
258,9,24,0,0,259,0,3,0,0,259,9,25,0,0,
261,0,2,0,0,261,9,23,0,0,262,0,1,0,0,262,4,27,0,0,262,5,10,0,0,262,7,10,0,0,262,9,6,0,0,263,0,2,0,0,
263,4,24,0,0,263,5,9,0,0,263,6,9,0,0,263,7,9,0,0,263,8,8,0,0,263,9,8,0,0,264,0,28,0,0,264,1,5,0,0,264,4,29,0,0,264,5,19,0,0,264,7,4,0,0,265,0,8,0,0,265,1,2,0,0,
265,7,29,0,0,265,8,21,0,0,265,9,4,0,0,266,1,2,0,0,266,9,24,0,0,267,0,9,0,0,267,1,28,0,0,267,2,10,0,0,267,4,5,0,0,
267,9,25,0,0,268,0,8,0,0,268,1,9,0,0,268,2,8,0,0,268,3,8,0,0,268,4,28,0,0,268,5,5,0,0,269,1,9,0,0,269,4,9,0,0,269,5,2,0,0,269,9,25,0,0,
270,0,26,0,0,270,1,19,0,0,270,3,19,0,0,270,5,7,0,0,271,0,3,0,0,271,8,27,0,0,271,9,6,0,0,
272,7,27,0,0,272,8,6,0,0,272,9,9,0,0,273,0,2,0,0,273,7,25,0,0,273,8,8,0,0,273,9,13,0,0,274,0,1,0,0,
274,9,8,0,0,275,0,1,0,0,275,3,27,0,0,275,4,10,0,0,275,6,14,0,0,275,7,6,0,0,275,8,13,0,0,276,0,2,0,0,276,3,23,0,0,276,4,13,0,0,276,5,9,0,0,276,6,13,0,0,276,7,8,0,0,276,8,8,0,0,276,9,13,0,0,
277,0,1,0,0,277,3,29,0,0,277,4,19,0,0,277,6,4,0,0,277,9,8,0,0,278,0,2,0,0,278,6,29,0,0,278,7,4,0,0,278,8,9,0,0,279,0,28,0,0,
279,1,5,0,0,279,7,29,0,0,279,8,4,0,0,279,9,8,0,0,280,0,9,0,0,280,1,28,0,0,280,2,14,0,0,280,3,5,0,0,280,8,25,0,0,281,0,8,0,0,281,1,9,0,0,
281,2,9,0,0,281,3,28,0,0,281,4,5,0,0,281,9,9,0,0,282,1,9,0,0,282,2,8,0,0,282,3,9,0,0,282,4,2,0,0,282,8,29,0,0,282,9,4,0,0,283,0,9,0,0,283,1,8,0,0,
283,3,9,0,0,283,4,28,0,0,283,5,5,0,0,283,9,25,0,0,284,0,8,0,0,284,2,9,0,0,284,3,9,0,0,284,4,9,0,0,284,5,2,0,0,285,1,9,0,0,285,2,26,0,0,285,3,19,0,0,
285,5,7,0,0,285,9,25,0,0,286,0,9,0,0,286,1,9,0,0,286,2,2,0,0,287,0,26,0,0,287,1,21,0,0,287,2,7,0,0,
287,9,24,0,0,288,0,2,0,0,288,9,25,0,0,289,0,1,0,0,
290,0,3,0,0,290,4,27,0,0,290,5,14,0,0,290,6,5,0,0,290,9,24,0,0,291,3,27,0,0,291,4,6,0,0,291,5,9,0,0,291,6,3,0,0,291,9,23,0,0,292,0,2,0,0,
292,3,23,0,0,292,4,9,0,0,292,5,8,0,0,292,9,24,0,0,293,0,3,0,0,293,3,24,0,0,293,4,9,0,0,293,6,1,0,0,293,9,24,0,0,294,3,23,0,0,
294,4,9,0,0,294,5,9,0,0,294,6,2,0,0,294,9,23,0,0,295,0,2,0,0,295,3,23,0,0,295,4,9,0,0,295,5,9,0,0,295,6,3,0,0,295,9,24,0,0,296,0,3,0,0,296,3,23,0,0,296,4,8,0,0,
296,5,8,0,0,296,9,23,0,0,297,3,23,0,0,297,6,2,0,0,297,9,24,0,0,298,0,1,0,0,298,3,29,0,0,298,4,19,0,0,
298,6,7,0,0,298,9,25,0,0,299,0,1,0,0,300,0,3,0,0,
300,9,25,0,0,302,0,28,0,0,302,1,5,0,0,302,5,17,0,0,302,9,6,0,0,
303,0,8,0,0,303,1,28,0,0,303,2,5,0,0,303,9,8,0,0,304,1,9,0,0,304,2,2,0,0,305,0,9,0,0,
305,1,8,0,0,305,2,28,0,0,305,3,5,0,0,305,9,4,0,0,306,0,8,0,0,306,2,8,0,0,306,3,28,0,0,306,4,10,0,0,306,6,5,0,0,306,9,23,0,0,307,1,9,0,0,
307,3,8,0,0,307,4,9,0,0,307,5,8,0,0,307,6,3,0,0,307,9,25,0,0,308,0,8,0,0,308,1,8,0,0,308,2,9,0,0,308,4,8,0,0,309,2,8,0,0,309,3,9,0,0,
309,5,26,0,0,309,6,7,0,0,309,9,25,0,0,310,0,8,0,0,310,1,9,0,0,310,3,9,0,0,310,4,26,0,0,310,5,7,0,0,311,1,26,0,0,311,2,19,0,0,311,4,7,0,0,
311,9,24,0,0,312,0,8,0,0,312,1,3,0,0,312,8,27,0,0,312,9,6,0,0,313,7,27,0,0,313,8,6,0,0,313,9,8,0,0,
314,0,9,0,0,314,1,1,0,0,314,6,27,0,0,314,7,6,0,0,314,8,9,0,0,315,0,26,0,0,315,1,7,0,0,315,6,25,0,0,315,7,9,0,0,315,8,9,0,0,315,9,8,0,0,316,0,3,0,0,
316,7,9,0,0,316,8,8,0,0,317,6,24,0,0,317,7,9,0,0,317,9,9,0,0,318,0,2,0,0,318,6,29,0,0,318,7,19,0,0,
318,9,4,0,0,319,0,1,0,0,319,9,24,0,0,320,0,2,0,0,320,3,27,0,0,320,4,5,0,0,320,9,25,0,0,
321,0,1,0,0,321,3,29,0,0,321,4,7,0,0,322,0,1,0,0,322,9,24,0,0,323,0,3,0,0,
323,9,23,0,0,324,3,27,0,0,324,4,10,0,0,324,6,5,0,0,324,9,24,0,0,325,0,1,0,0,325,3,29,0,0,325,4,19,0,0,325,6,7,0,0,325,9,23,0,0,
326,0,2,0,0,326,9,24,0,0,327,0,1,0,0,327,9,25,0,0,328,0,3,0,0,
329,4,27,0,0,329,5,5,0,0,329,9,25,0,0,330,0,1,0,0,330,4,25,0,0,330,5,3,0,0,331,0,2,0,0,
331,9,25,0,0,332,0,3,0,0,332,3,27,0,0,332,4,6,0,0,332,5,2,0,0,333,3,29,0,0,333,4,21,0,0,333,5,7,0,0,333,9,23,0,0,
334,0,2,0,0,334,9,25,0,0,335,0,1,0,0,336,0,3,0,0,
336,9,24,0,0,337,9,24,0,0,338,0,2,0,0,338,9,25,0,0,
339,0,1,0,0,340,0,3,0,0,340,4,15,0,0,340,7,10,0,0,340,9,6,0,0,
341,7,8,0,0,341,8,13,0,0,341,9,8,0,0,342,0,2,0,0,342,8,8,0,0,343,0,3,0,0,343,7,8,0,0,
343,9,13,0,0,344,8,8,0,0,344,9,8,0,0,345,0,1,0,0,345,7,4,0,0,
346,0,3,0,0,346,7,29,0,0,346,8,4,0,0,346,9,13,0,0,347,8,24,0,0,347,9,8,0,0,348,0,2,0,0,
348,8,25,0,0,349,0,28,0,0,349,1,15,1,1,349,9,8,0,0,350,0,8,0,0,350,7,27,0,0,350,8,6,0,0,
351,7,25,0,0,351,8,8,0,0,351,9,9,0,0,352,0,8,0,0,352,9,8,0,0,353,7,24,0,0,
353,8,9,0,0,354,0,26,0,0,354,7,29,0,0,354,8,4,0,0,354,9,13,0,0,355,0,3,0,0,355,8,25,0,0,
355,9,8,0,0,357,0,2,0,0,357,8,24,0,0,357,9,13,0,0,
358,0,3,0,0,358,8,23,0,0,358,9,9,0,0,359,8,23,0,0,359,9,13,0,0,360,0,3,0,0,
360,8,25,0,0,360,9,8,0,0,362,0,1,0,0,362,8,24,0,0,
362,9,13,0,0,363,0,3,0,0,363,8,25,0,0,363,9,9,0,0,364,9,9,0,0,
365,0,2,0,0,365,8,24,0,0,365,9,8,0,0,366,0,1,0,0,366,8,23,0,0,367,0,3,0,0,
367,8,24,0,0,367,9,13,0,0,368,8,23,0,0,368,9,9,0,0 };






