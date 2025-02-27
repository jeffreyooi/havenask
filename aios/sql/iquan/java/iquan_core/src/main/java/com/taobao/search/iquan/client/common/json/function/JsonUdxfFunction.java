package com.taobao.search.iquan.client.common.json.function;

import com.taobao.search.iquan.core.api.exception.ExceptionUtils;
import com.taobao.search.iquan.core.api.exception.IquanNotValidateException;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.taobao.search.iquan.core.api.schema.FunctionType;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class JsonUdxfFunction {
    private static final Logger logger = LoggerFactory.getLogger(JsonUdxfFunction.class);

    @JsonProperty(value = "prototypes", required = true)
    private List<JsonUdxfSignature> prototypes = new ArrayList<>(1);

    @JsonProperty(value = "properties")
    private Map<String, Object> properties = new HashMap<>(1);

    public JsonUdxfFunction() {
    }

    public List<JsonUdxfSignature> getPrototypes() {
        return prototypes;
    }

    public Map<String, Object> getProperties() {
        return properties;
    }

    @JsonIgnore
    public boolean isValid(FunctionType functionType) {
        boolean isValid = true;
        try {
            ExceptionUtils.throwIfTrue(prototypes == null, "prototypes is null");
            ExceptionUtils.throwIfTrue(prototypes.stream().anyMatch(v -> !v.isValid(functionType)),
                    "one of prototypes is not valid");
        } catch (IquanNotValidateException e) {
            logger.error(e.getMessage());
            isValid = false;
        }
        return isValid;
    }
}
