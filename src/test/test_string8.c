
internal bool TEST_string8New(String8 s1, char *str, u64 size) {
    return s1.size == size && (memcmp(s1.str, str, size) == 0);
}

internal bool TEST_string8IsEqual(String8 s1, String8 s2) {
    return s1.size == s2.size && (memcmp(s1.str, s2.str, s1.size) == 0);
}

internal bool TEST_string8Concat(Arena* arena, String8 s1, String8 s2, String8 s1_s2) {
    String8 str_res = Str8Concat(arena,s1, s2);
    bool res = TEST_string8IsEqual(str_res, s1_s2);
    return res;
}

internal bool TEST_string8Append(Arena* arena, String8 s1, String8 s2, String8 s1_s2) {
    Str8Append(arena, &s1, s2);
    bool res = TEST_string8IsEqual(s1, s1_s2);
    return res;
}

void TEST_string8() {
    Arena *arena = ArenaAlloc();

    char* c_str1 = "Hello";
    char* c_str2 = "üüThis is a different test üä/$ßßüewhä🐝";
    String8 s1 = STR8_LIT("Hello");
    String8 s2 = STR8_LIT("üüThis is a different test üä/$ßßüewhä🐝");
    String8 s1_2 = Str8FromLiteral(c_str1);
    String8 s2_2 = Str8FromLiteral(c_str2);

    bool str8New1_TRUE = TEST_string8New(s1, c_str1, strlen(c_str1));
    bool str8New2_TRUE = TEST_string8New(s2, c_str2, strlen(c_str2));
    bool str8New3_TRUE = TEST_string8New(s1_2, c_str1, strlen(c_str1));
    bool str8New4_TRUE = TEST_string8New(s2_2, c_str2, strlen(c_str2));
    bool str8New5_TRUE = TEST_string8New(s2, c_str2, strlen(c_str2));
    bool str8New6_FALSE = TEST_string8New(s1, c_str2, strlen(c_str2));
    bool str8New7_FALSE = TEST_string8New(s2_2, c_str1, strlen(c_str1));

    assert(str8New1_TRUE);
    assert(str8New2_TRUE);
    assert(str8New3_TRUE);
    assert(str8New4_TRUE);
    assert(str8New5_TRUE);
    assert(!str8New6_FALSE);
    assert(!str8New7_FALSE);
    
    bool str8Equal1_TRUE = TEST_string8IsEqual(s1, s1);
    bool str8Equal2_TRUE = TEST_string8IsEqual(s2,s2);
    bool str8Equal3_FALSE = TEST_string8IsEqual(s1, s2);
    bool str8Equal4_FALSE = TEST_string8IsEqual(s2, s1);

    assert(str8Equal1_TRUE);
    assert(str8Equal2_TRUE);
    assert(!str8Equal3_FALSE);
    assert(!str8Equal4_FALSE);

    String8 s1_s2 = STR8_LIT("HelloüüThis is a different test üä/$ßßüewhä🐝");
    String8 s2_s1 = STR8_LIT("üüThis is a different test üä/$ßßüewhä🐝Hello");

    bool str8Concat1_TRUE = TEST_string8Concat(arena, s1, s2, s1_s2);
    bool str8Concat2_TRUE = TEST_string8Concat(arena, s2, s1, s2_s1);
    bool str8Concat3_FALSE = TEST_string8Concat(arena, s2, s1, s1_s2);
    bool str8Concat4_FALSE = TEST_string8Concat(arena, s2, s1, s1);

    assert(str8Concat1_TRUE);
    assert(str8Concat2_TRUE);
    assert(!str8Concat3_FALSE);
    assert(!str8Concat4_FALSE);


    bool str8Append1_TRUE = TEST_string8Append(arena, s1, s2, s1_s2);
    bool str8Append2_TRUE = TEST_string8Append(arena, s2, s1, s2_s1);
    bool str8Append3_FALSE = TEST_string8Append(arena, s2, s1, s1_s2);
    bool str8Append4_FALSE = TEST_string8Append(arena, s2, s1, s1);

    assert(str8Append1_TRUE);
    assert(str8Append2_TRUE);
    assert(!str8Append3_FALSE);
    assert(!str8Append4_FALSE);

    printf("String8 TESTS SUCCESSFUL\n");
}

